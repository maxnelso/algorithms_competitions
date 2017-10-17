import math
import sys

def main():
  n = int(raw_input());
  digits = 1
  out = 0
  while True:
    num_of_digit = 10**(digits - 1) * 9
    if num_of_digit > n:
      out += digits * n
      break
    else:
      n -= num_of_digit
      out += digits * num_of_digit
      digits += 1
  print out

if __name__ == '__main__':
  main()
