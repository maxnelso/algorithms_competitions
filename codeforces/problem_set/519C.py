import math
import sys

def main():
  MAX = 10e6
  n, m = map(int, raw_input().split())
  best = 0
  for i in range(int(MAX)):
    if i * 2 > n or i > m:
      break
    experienced_left = n - (i * 2)
    noobs_left = m - i
    best = max(best, min(experienced_left, noobs_left / 2) + i)
  print best


if __name__ == '__main__':
  main()
