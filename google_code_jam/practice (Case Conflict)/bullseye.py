import os
import sys
import math

"""
The basic code for reading a file, should return a string
"""
def parse_input(input_file):
  f = open(input_file, "r")
  test_cases = int(f.readline())
  final_string = ""
  for i in range(test_cases):
    params = f.readline().split()
    r = int(params[0])
    t = int(params[1])
    final_string = final_string + "Case #{0}: {1}\n".format(i+1, get_count(r,t))
  f.close()
  return final_string

def get_count(r, t):
  count = 0
  index = 0
  while t > 0:
    t = t - (((r+index+1)**2) - ((r+index)**2))
    print t
    count = count + 1
    index = index + 2

  if t < 0:
    return max(0, count - 1)
  return count

"""
Writes a string to the file of the form X-Y-output.txt,
where X is the name of this script and Y is the name of the
test case
"""
def write_output(answer_string):
  script_name = os.path.splitext(sys.argv[0])[0] + "-"
  f = open("Outputs/" + script_name +"output.txt","w")
  f.write(answer_string)
  f.close()

if __name__ == "__main__":
  if len(sys.argv) > 1:
    answer_string = parse_input(sys.argv[1])
    if answer_string == None:
      print "No answer given"
    else:
      write_output(answer_string)
  else:
    print "Pass in the input file"
