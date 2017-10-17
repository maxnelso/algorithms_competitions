import math
import sys

def main():
  n = raw_input()
  binary_string = ''
  out = 0
  for c in n:
    if c == '7':
      binary_string += '1'
    else:
      binary_string += '0'
  for i in range(1, len(n)):
    out += 2 ** i
  offset = int(binary_string, 2)
  out += offset
  print out + 1

if __name__ == '__main__':
  main()
