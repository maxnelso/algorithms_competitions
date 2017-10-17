import math
import sys

def main():
  n, m = map(int, raw_input().split())
  nums = map(int, raw_input().split())
  nums.sort()
  out = 0
  for i in range(m):
    if nums[i] >= 0:
      break
    out += nums[i]
  print abs(out)

if __name__ == '__main__':
  main()
