#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  float raw_bit_rate = atoi(argv[2]);

  FILE* input_file = fopen(input_filename, "r");

  float bit_rate = 0;
  int bit_count = 0;
  unsigned char cur_bit = 0;
  while(1) {
    int one_count = 0;
    while(cur_bit == 1) {
      fread(&cur_bit, 1, 1, input_file);
      one_count++;
    }
    printf("one count (%d)\n", one_count);

    int zero_count = 0;
    while(cur_bit == 0) {
      fread(&cur_bit, 1, 1, input_file);
      zero_count++;
    }
    printf("zero count (%d)\n", zero_count);

    float total_count = one_count + zero_count;
    float bits_per_second = raw_bit_rate / total_count;
    printf("bits_per_second (%f)\n", bits_per_second);
  }
}

