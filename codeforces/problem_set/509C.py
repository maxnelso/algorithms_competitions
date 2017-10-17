import math
import sys

def main():
  n = int(raw_input())
  nums = []
  for i in range(n):
    nums.append(int(raw_input()))
  start = nums[0]
  out = ""
  while start > 9:
    out = "9" + out
    start -= 9
  out = str(start) + out
  current = int(out)
  print current


if __name__ == '__main__':
  main()
