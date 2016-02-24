#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  char* output_filename = argv[2];

  FILE* output_file = fopen(output_filename, "w");
  FILE* input_file = fopen(input_filename, "r");

  int output_row_size = 128;
  int row_size = 2048;

  int iq_byte_length = 8;
  char buffer[iq_byte_length];
  float cur_i = 0.0f;
  float cur_q = 0.0f;
  float row_i[row_size];
  float row_q[row_size];

  char byte_swap_buff[4];

  int signal_index = 0;
  int signal_averaging_window_size = 5;
  int half_window_size = signal_averaging_window_size / 2;

  unsigned int row_count = 0;
  while(1) {
    row_count++;
/*
    if(row_count % 1000 == 0) {
      printf("row_count (%u) signal_index (%d)\n", row_count, signal_index);
    }
*/


    for(int row_index = 0; row_index < row_size; row_index++) {
      fread(&buffer, iq_byte_length, 1, input_file);
      char* i_float_data = (char*)&cur_i;
      for(int i = 0; i < 4; i++) {
        i_float_data[i] = buffer[i];
      }
      row_i[row_index] = cur_i;

      char* q_float_data = (char*)&cur_q;
      for(int i = 0; i < 4; i++) {
        i_float_data[i] = buffer[i];
      }
      row_q[row_index] = cur_q;
    }

/*
*/
    float max_average = 0.0f;
    for(int row_index = 0; row_index < (row_size - signal_averaging_window_size); row_index++) {
      long sum = 0;
      for(int averaging_window_index = 0; averaging_window_index < signal_averaging_window_size; averaging_window_index++) {
        sum += row_i[row_index + averaging_window_index];
      }
      float average = sum / signal_averaging_window_size;
      if(average > max_average) {
        signal_index = row_index + half_window_size;
      }
    }

    int min_write_index = signal_index;
    if(min_write_index + output_row_size >= row_size) {
      min_write_index = row_size - output_row_size;
    }

    for(int write_index = min_write_index; write_index < (min_write_index + output_row_size); write_index++) {
      char* write_i = (char*)&(row_i[write_index]);
      fwrite(write_i, 4, 1, output_file);

      char* write_q = (char*)&(row_q[write_index]);
      fwrite(write_q, 4, 1, output_file);
    }
/*
    for(int write_index = 0; write_index < output_row_size; write_index++) {
      char* write_mag = (char*)&(row_i[write_index]);

      fwrite(write_mag, 4, 1, output_file);
    }
*/
  }
}

#ifdef _PYTHON_IS_FAST_
input_filename = sys.argv[1]
output_filename = sys.argv[2]
input_width = int(sys.argv[3])
output_width = int(sys.argv[4])

print "input file: ",input_filename
print "output file: ", output_filename
print "input width: ", input_width
print "output width: ", output_width

fft_in_file = open(input_filename)
#fft_out_file = open(output_filename, "w")

#current_row = []
#current_strong_signal_row = []
#found_signal_index = 0
while True:
   for column_num in range(output_width):
#       print 'column:', column_num
       mag_bytes = fft_in_file.read(4)
       if mag_bytes == "":
          break

       mag = struct.unpack_from('<f', mag_bytes)[0]
#       mag *= 1000
       mag = int(mag)
       if mag >= 256:
          mag = 255

#       current_row.append(mag)
#       current_strong_signal_row.append(mag - 128)

#endif
