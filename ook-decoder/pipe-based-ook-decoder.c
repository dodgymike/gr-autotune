#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

void float_to_buf(float in, unsigned char* buf) {
  unsigned char* in_bytes = (unsigned char*)&in;
  for(int i = 0; i < 4; i++) {
    buf[i] = in_bytes[i];
  }
}

void jam(int jam_on, FILE* jam_file) {
  unsigned char buf[4];

/*
      float_to_buf(row_i[write_index], buffer);
      fwrite(buffer, 4, 1, output_file);
*/

  float jam_i = jam_on ? 0xffff : 0x0000;
  float_to_buf(jam_i, buf);
  fwrite(buf, 4, 1, jam_file);
  float jam_q = 0xffff;
  float_to_buf(jam_q, buf);
  fwrite(buf, 4, 1, jam_file);

  fflush(jam_file);

//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
}

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  char* jam_filename = argv[2];
  float raw_bit_rate = atoi(argv[3]);

  FILE* jam_file = fopen(jam_filename, "w");
  FILE* input_file = fopen(input_filename, "r");

  float bit_rate = 0;
  int bit_count = 0;
  unsigned char cur_bit = 0;
  unsigned char cur_jam_bit = 0;

  // gaah! naming!
  int decoded_bit_count = 0;

  int max_symbol_bit_count = 128;
  int symbol_bits[max_symbol_bit_count];
  int symbol_bit_index = 0;

  int jam_on = 0;

  while(1) {
    int one_count = 0;
    while(cur_bit == 1) {
      jam(jam_on, jam_file);
      fread(&cur_bit, 1, 1, input_file);
      one_count++;
    }
//    printf("one count (%d)\n", one_count);

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
        jam_on = 1;
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

      jam(jam_on, jam_file);
      fread(&cur_bit, 1, 1, input_file);
      zero_count++;
    }

//    printf("zero count (%d)\n", zero_count);

    float total_count = one_count + zero_count;
    float bits_per_second = raw_bit_rate / total_count;
//    printf("bits_per_second (%f)\n", bits_per_second);

    float on_off_ratio = (float)one_count / total_count;
    int on_off = (on_off_ratio > 0.6f);
    int dead_space = (on_off_ratio <= 0.2f);

    if(dead_space) {
      jam_on = 0;
    }
//    printf("on_off_ratio (%f) on_off (%d) dead_space (%d)\n", on_off_ratio, on_off, dead_space);

/*
    if(dead_space) {
      printf("DEAD SPACE\n");
    }
*/

    symbol_bits[symbol_bit_index++] = on_off;

    if(symbol_bit_index >= max_symbol_bit_count) {
      printf("WTF? too many bits in the symbol\n");
      exit(-1);
    }
    
    decoded_bit_count++;
  }
}

