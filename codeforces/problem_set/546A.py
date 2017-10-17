import math
import sys

def main():
  k, n, w = map(int, raw_input().split())
  total = 0
  for i in range(1, w + 1):
    total += k * i

  print max(0, total - n)

if __name__ == '__main__':
  main()
