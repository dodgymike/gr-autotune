#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  float raw_bit_rate = atoi(argv[2]);

  FILE* input_file = fopen(input_filename, "r");

  float bit_rate = 0;
  int bit_count = 0;
  unsigned char cur_bit = 0;

  // gaah! naming!
  int decoded_bit_count = 0;

  int max_symbol_bit_count = 128;
  int symbol_bits[max_symbol_bit_count];
  int symbol_bit_index = 0;

  while(1) {
    int one_count = 0;
    while(cur_bit == 1) {
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

