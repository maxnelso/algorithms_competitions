import math
import sys

def main():
  s = raw_input()
  seen = {}
  left_index = 0
  right_index = 0
  out = 0
  while left_index < len(s):
    if s[left_index] == '(':
      while right_index < len(s):
        if s[right_index] == ')' and right_index > left_index:
          out += 2
          right_index += 1
          break
        else:
          right_index += 1
    left_index += 1
  print out

if __name__ == '__main__':
  main()
