import math
import sys

def main():
  n = int(raw_input())
  ranges = []
  for i in range(n):
    l, r = map(int, raw_input().split())
    ranges.append((l, r))
  out = 0
  for i in range(1, 10001):
    p = 1
    for j in range(len(ranges)):

    out += p * i
  print out


if __name__ == '__main__':
  main()
