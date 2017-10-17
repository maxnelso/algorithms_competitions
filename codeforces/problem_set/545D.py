import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  t = 0
  nums.sort()
  out = 0
  for num in nums:
    if num >= t:
      out += 1
    t += num
  print out

if __name__ == '__main__':
  main()
