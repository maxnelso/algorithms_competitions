import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  p = []
  m = []
  pe = []
  for i in range(len(nums)):
    if nums[i] == 1:
      p.append(i + 1)
    if nums[i] == 2:
      m.append(i + 1)
    if nums[i] == 3:
      pe.append(i + 1)
  total = min(len(p), len(m), len(pe))
  print total
  for i in range(total):
    print p[i], m[i], pe[i]

if __name__ == '__main__':
  main()
