import math
import sys

def main():
  n, a, b, c = map(int, raw_input().split())
  best = 10**20
  for i in range(5):
    for j in range(5):
      for k in range(5):
        if (n + i + 2*j + 3*k) % 4 == 0:
          best = min(best, i * a + j * b + k * c)
  print best

if __name__ == '__main__':
  main()
