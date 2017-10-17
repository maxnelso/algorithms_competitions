import math
import sys

def main():
  n = int(raw_input())
  best_quality = [0] * n
  for i in range(n):
    a, b = map(int, raw_input().split())
    best_quality[a - 1] = max(best_quality[a - 1], b)

  if all(x<=y for x, y in zip(best_quality, best_quality[1:])):
    print "Poor Alex"
  else:
    print "Happy Alex"


if __name__ == '__main__':
  main()
