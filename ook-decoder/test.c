#include <stdio.h>
#include <stdlib.h>

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

  int jam_on = 1;
  while(1) {
      jam(jam_on, jam_file);
  }
}

