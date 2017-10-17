import math
import sys

def main():
  n, m = map(int, raw_input().split())
  socks = n
  day = 0
  while socks > 0:
    day += 1
    if day % m == 0 and day != 0:
      socks += 1
    socks -= 1
  print day

if __name__ == '__main__':
  main()
