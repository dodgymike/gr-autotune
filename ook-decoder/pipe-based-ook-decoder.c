#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>

float jam_data() {
  float rand_data = rand();
  rand_data /= (float)RAND_MAX;

  rand_data *= 50;

  return rand_data;
}

void float_to_buf(float in, unsigned char* buf) {
  unsigned char* in_bytes = (unsigned char*)&in;
  for(int i = 0; i < 4; i++) {
    buf[i] = in_bytes[i];
  }
}

void jam(int jam_on, FILE* jam_file) {
  unsigned char buf[4];

  float jam_i = jam_on ? jam_data() : 0x0000;
  float_to_buf(jam_i, buf);
  fwrite(buf, 4, 1, jam_file);
  float jam_q = jam_on ? jam_data() : 0x0000;
  float_to_buf(jam_q, buf);
  fwrite(buf, 4, 1, jam_file);

//  fflush(jam_file);
}

struct jam_args {
  FILE* jam_file;
  int* jam_on;
  pthread_mutex_t* jam_lock;
};

void* jam_loop(void* arg) {
  struct jam_args* args = (struct jam_args*)arg;

  FILE* jam_file = args->jam_file;
  int* jam_on = args->jam_on;
  pthread_mutex_t* jam_lock = args->jam_lock;

  int local_jam_on = 0;
  while(1) {
      pthread_mutex_lock(jam_lock);
        int local_jam_on = *jam_on;
      pthread_mutex_unlock(jam_lock);
/*
      if(local_jam_on) {
        printf("JAM LOOP JAMMING\n");
      }
*/

    jam(local_jam_on, jam_file);

/*
      for(int i = 0; i < 250000; i++) {
        jam(1, jam_file);
      }
      for(int i = 0; i < 250000; i++) {
        jam(0, jam_file);
      }
*/  
  }
}

struct ook_args {
  FILE* ook_file;
  float* raw_bit_rate;
  int* jam_on;
  pthread_mutex_t* jam_lock;
};

void* ook_loop(void* arg) {
  struct ook_args* args = (struct ook_args*)arg;

  FILE* ook_file = args->ook_file;
  float raw_bit_rate = *(args->raw_bit_rate);
  int* jam_on = args->jam_on;
  pthread_mutex_t* jam_lock = args->jam_lock;

  float bit_rate = 0;
  int bit_count = 0;
  unsigned char cur_bit = 0;
  unsigned char cur_jam_bit = 0;

  // gaah! naming!
  int decoded_bit_count = 0;

  int max_symbol_bit_count = 128;
  int symbol_bits[max_symbol_bit_count];
  int symbol_bit_index = 0;

  while(1) {
    int one_count = 0;
    while(cur_bit == 1) {
      fread(&cur_bit, 1, 1, ook_file);
      one_count++;
        pthread_mutex_lock(jam_lock);
        if(*jam_on > 0) {
          (*jam_on)--;
        }
        pthread_mutex_unlock(jam_lock);
    }
//    printf("one count (%d)\n", one_count);
/*
        pthread_mutex_lock(jam_lock);
          printf("JAM ON!\n");
          *jam_on = 1;
        pthread_mutex_unlock(jam_lock);
*/

    // end of byte
    if((decoded_bit_count > 0) && (one_count == 0)) {
      decoded_bit_count = 0;
      printf("end of symbol: ");

      if(symbol_bit_index > 13) {
        for(int i = 0; i < (symbol_bit_index - 1); i++) {
          printf("%d", symbol_bits[i]);
        }
        printf("\n");
      } else if(symbol_bit_index == 13) {
        pthread_mutex_lock(jam_lock);
          printf("JAM ON!\n");
          *jam_on = 50000;
        pthread_mutex_unlock(jam_lock);
      }

      symbol_bit_index = 0;

      continue;
    }

    int four_times_one_count = one_count * 4;
    int zero_count = 0;
    while(cur_bit == 0) {
      // make sure we get that final bit
      // TODO be more sane about the final bit on/off state. Right now we basically always set it to 'off'.
      if((one_count > 0) && (zero_count > four_times_one_count)) {
        break;
      }

      fread(&cur_bit, 1, 1, ook_file);
      zero_count++;
        pthread_mutex_lock(jam_lock);
        if(*jam_on > 0) {
          (*jam_on)--;
        }
        pthread_mutex_unlock(jam_lock);
/*
*/
    }

//    printf("zero count (%d)\n", zero_count);

    float total_count = one_count + zero_count;
    float bits_per_second = raw_bit_rate / total_count;
//    printf("bits_per_second (%f)\n", bits_per_second);

    float on_off_ratio = (float)one_count / total_count;
    int on_off = (on_off_ratio > 0.6f);
    int dead_space = (on_off_ratio <= 0.2f);

/*
    if(dead_space) {
        pthread_mutex_lock(jam_lock);
          //printf("JAM OFF\n");
          (*jam_on)--;
        pthread_mutex_unlock(jam_lock);
    }
*/
//    printf("on_off_ratio (%f) on_off (%d) dead_space (%d)\n", on_off_ratio, on_off, dead_space);

/*
    if(dead_space) {
      printf("DEAD SPACE\n");
    }
*/

    symbol_bits[symbol_bit_index++] = on_off;

    if(symbol_bit_index >= max_symbol_bit_count) {
      //printf("WTF? too many bits in the symbol\n");
      //exit(-1);
      symbol_bit_index = 0;
    }
    
    decoded_bit_count++;
  }
}

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  char* jam_filename = argv[2];
  float raw_bit_rate = atoi(argv[3]);

  FILE* jam_file = fopen(jam_filename, "w");
  FILE* ook_file = fopen(input_filename, "r");

  pthread_mutex_t jam_lock;
  pthread_mutex_init(&jam_lock, NULL);

  int jam_on = 0;

  pthread_t ook_thread;
  pthread_t jam_thread;

  struct ook_args oargs;
  oargs.ook_file = ook_file;
  oargs.raw_bit_rate = &raw_bit_rate;
  oargs.jam_on = &jam_on;
  oargs.jam_lock = &jam_lock;
  pthread_create(&ook_thread, NULL, ook_loop, &oargs);

  struct jam_args jargs;
  jargs.jam_file = jam_file;
  jargs.jam_on = &jam_on;
  jargs.jam_lock = &jam_lock;
  pthread_create(&jam_thread, NULL, jam_loop, &jargs);

  while(1) {
    sleep(1000);
  }

  return 0;
}

