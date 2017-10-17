import math
import sys

def main():
  h, n = map(int, raw_input().split())
  n -= 1
  out = 0
  left = 0
  half = 1 << (h - 1)
  for i in range(h):
    if n >= half:
      if left == 0:
        out += half * 2
      else:
        out += 1
        left = 0
      n -= half
    else:
      if left == 1:
        out += half * 2
      else:
        out += 1
        left = 1
    half /= 2
  print out

if __name__ == '__main__':
  main()
