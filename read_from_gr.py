#from __future__ import print_function

import struct
import sys

import png

input_filename = sys.argv[1]
output_filename = sys.argv[2]
input_width = int(sys.argv[3])
output_width = int(sys.argv[4])

print "input file: ",input_filename
print "output file: ", output_filename
print "input width: ", input_width
print "output width: ", output_width

fft_in_file = open(input_filename)
fft_out_file = open(output_filename, "w")

current_row = []
current_strong_signal_row = []
found_signal_index = 0
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

       current_row.append(mag)
       current_strong_signal_row.append(mag - 128)

   
   row_index = 0
   strong_signal_count = 0
   for strong_signal in current_strong_signal_row:
      row_index += 1
      if strong_signal >= 0:
        #print "got strong signal!"
        strong_signal_count += 1
      else:
        strong_signal_count = 0

      if strong_signal_count >= output_width:
        found_signal_index = row_index - 2
        break

   for signal_element in current_row[found_signal_index:found_signal_index+output_width]:
     fft_out_file.write(struct.pack('<f', signal_element))

   current_row = []
   current_strong_signal_row = []

