import math
import sys

def main():
  n = int(raw_input())
  original = raw_input()
  final = raw_input()
  out = 0
  for i in range(len(final)):
    test = abs(int(original[i]) - int(final[i]))
    # top
    top = int(original[i]) + (9 - int(final[i])) + 1
    bottom = (9 - int(original[i])) + int(final[i]) + 1
    out += min(test, min(top, bottom))
  print out

if __name__ == '__main__':
  main()
