import math
import sys

def arithmetic(a1, an, n):
  return n * (a1 + an) / 2

def veggies(A, B, i):
  return A + (i - 1) * B

def main():
  A, B, n = map(int, raw_input().split())
  for i in range(n):
    l, t, m = map(int, raw_input().split())
    out = -1
    low = l
    high = 10000000
    while high >= low:
      mid = low + (high - low) / 2
      s = arithmetic(veggies(A, B, l), veggies(A, B, mid), mid - l + 1)
      if t * m >= s and veggies(A, B, mid) <= t:
        out = max(out, mid)
        low = mid + 1
      else:
        high = mid - 1

    print out

if __name__ == '__main__':
  main()
