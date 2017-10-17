import math
import sys

class Hello(arg1, arg2):


def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  for num in nums:
    index = 1
    for a in nums:
      if a > num:
        index += 1
    print index,

if __name__ == '__main__':
  main()
