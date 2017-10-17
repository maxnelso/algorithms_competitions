import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  counts = {}
  for i in nums:
    if i in counts:
      counts[i] += 1
    else:
      counts[i] = 1
  out = [0] * int(1e5 + 1)
  out[0] = 0
  if 1 not in counts:
    counts[1] = 0
  out[1] = counts[1]
  for i in range(2, int(1e5 + 1)):
    if i not in counts:
      counts[i] = 0
    out[i] = max(out[i - 1], out[i - 2] + counts[i] * i)
  print max(out)
if __name__ == '__main__':
  main()
