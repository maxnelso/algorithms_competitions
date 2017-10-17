import math
import sys

def main():
  n, m = map(int, raw_input().split())
  values = map(int, raw_input().split())
  best = 0
  for i in range(m):
    edge = map(int, raw_input().split())
    density = (values[edge[0] - 1] + values[edge[1] - 1]) / float(edge[2])
    best = max(density, best)
  print best

if __name__ == '__main__':
  main()
