import math
import sys

def count(a):
  out = 0
  for i in range(len(a) - 1):
    out = max(out, a[i + 1] - a[i])
  return out

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  out = 1000000
  for i in range(1, len(nums) - 1):
    out = min(out, count(nums[:i] + nums[i + 1:]))
  print out

if __name__ == '__main__':
  main()
