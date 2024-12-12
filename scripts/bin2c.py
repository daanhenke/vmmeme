from os import stat
from sys import argv

def bin2c(input_path: str, output_path: str, resource_id: str):
  input_stats = stat(input_path)
  with open(input_path, 'rb') as input_file:
    with open(output_path, 'w') as output_path:
      _generate_c_file(input_file, output_path, resource_id, input_stats.st_size)
def _generate_c_file(input_file, output_file, resource_id: str, file_size: int):
  read = input_file.read(1)
  size = 0

  output_file.write('unsigned int {}_size = {};\n\n'.format(resource_id, file_size))
  first_line = 'const char* {} = \"'.format(resource_id)
  output_file.write(first_line)
  line_size = len(first_line)

  while len(read) > 0:
    i = read[0]
    size += 1

    if i >= 32 and i != ord('"') and i != ord('\\') and i < 128:
      output_file.write(chr(i))
      line_size += 1
    elif i == ord('"'):
      output_file.write('\\"')
      line_size += 2
    elif i == ord('\\'):
      output_file.write('\\\\')
      line_size += 2
    elif i == ord('\n'):
      output_file.write('\\n')
      line_size += 2
    elif i == ord('\r'):
      output_file.write('\\r')
      line_size += 2
    elif i == ord('\t'):
      output_file.write('\\t')
      line_size += 2
    else:
      output_file.write('\\{:03o}'.format(i))
      line_size += 4

    if line_size > 120:
      output_file.write("\"\n\"")
      line_size = 0

    read = input_file.read(1)

  output_file.write("\";")

if __name__ == '__main__':
    if len(argv) != 4:
        exit(1)

    input_path = argv[1]
    output_path = argv[2]
    resource_id = argv[3]
    print("".format())
    bin2c(input_path, output_path, resource_id)
