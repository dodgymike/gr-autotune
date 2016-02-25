#include <stdio.h>
#include <stdlib.h>

void float_to_buf(float in, unsigned char* buf) {
  unsigned char* in_bytes = (unsigned char*)&in;
  for(int i = 0; i < 4; i++) {
    buf[i] = in_bytes[i];
  }
}

float buf_to_float(unsigned char* buf) {
  float out = 0.0f;

  unsigned char* out_bytes = (unsigned char*)&out;
  for(int i = 0; i < 4; i++) {
    out_bytes[i] = buf[i];
  }

  return out;
}

int find_output_start_index(int signal_index, int output_row_size, int row_size, int half_output_row_size) {
  int output_start_index = signal_index;

  // check for the top-end boundary
  if(output_start_index + output_row_size >= row_size) {
    output_start_index = row_size - output_row_size - 1;
  }

  // make sure the signal is in the middle
  output_start_index -= half_output_row_size;
  if(output_start_index < 0) {
    output_start_index = 0;
  }

  return output_start_index;
}

int main(int argc, char* argv[]) {
  char* input_filename = argv[1];
  char* output_filename = argv[2];
  int row_size = atoi(argv[3]);
  int output_row_size = atoi(argv[4]);

  FILE* output_file = fopen(output_filename, "w");
  FILE* input_file = fopen(input_filename, "r");

  //int output_row_size = 8;
  int half_output_row_size = output_row_size / 2;
  //int row_size = 512;

  unsigned char buffer[4];
  float cur_i = 0.0f;
  float cur_q = 0.0f;
  float row_i[row_size];
  float row_q[row_size];

  int signal_index = 0;
  int signal_averaging_window_size = output_row_size / 10;
  int half_window_size = signal_averaging_window_size / 2;

/*
  float row_sums[row_size];
  int row_counts[row_size];
  int row_average_window_size;
*/

  while(1) {
    for(int row_index = 0; row_index < row_size; row_index++) {
      fread(&buffer, 4, 1, input_file);
      row_i[row_index] = buf_to_float(buffer);
      fread(&buffer, 4, 1, input_file);
      row_q[row_index] = buf_to_float(buffer);
    }

      float max_average = 0.0f;
      for(int row_index = 0; row_index < (row_size - signal_averaging_window_size); row_index++) {
        long sum = 0;
        for(int averaging_window_index = 0; averaging_window_index < signal_averaging_window_size; averaging_window_index++) {
          sum += abs(row_i[row_index + averaging_window_index]);
        }
        float average = sum / signal_averaging_window_size;
        if(average > max_average) {
          signal_index = row_index + half_window_size;
          max_average = average;
        }
      }

    // HARD CODED
    //output_start_index = 6582;
    int output_start_index = find_output_start_index(signal_index, output_row_size, row_size, half_output_row_size);

    for(int write_index = output_start_index; write_index < (output_start_index + output_row_size); write_index++) {
      float_to_buf(row_i[write_index], buffer);
      fwrite(buffer, 4, 1, output_file);

      float_to_buf(row_q[write_index], buffer);
      fwrite(buffer, 4, 1, output_file);
    }
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
