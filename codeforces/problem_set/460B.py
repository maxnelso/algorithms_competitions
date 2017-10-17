import math
import sys

def test(a, b, c, x):
  sum_of_digits = sum([int(d) for d in str(x)])
  return x == b * (sum_of_digits ** a) + c

def main():
  a, b, c = map(int, raw_input().split())
  out = []
  for s in range(1, 100):
    x = b * (s ** a) + c
    if x > 0 and x < 10**9 and sum([int(d) for d in str(x)]) == s:
      out.append(x)
  print len(out)
  print ' '.join([str(i) for i in out])

if __name__ == '__main__':
  main()
