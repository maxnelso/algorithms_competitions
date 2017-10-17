import math
import sys

def main():
  n, m = map(int, raw_input().split())
  grid = []
  for i in range(n):
    grid.append(raw_input())
  vs = [0] * m
  rs = [0] * n
  total = 0
  for i in range(n):
    for j in range(m):
      if grid[i][j] == "*":
        vs[j] += 1
        rs[i] += 1
        total += 1

  for i in range(n):
    for j in range(m):
      if grid[i][j] == "*":
        if vs[j] + rs[i] - 1 == total:
          print "YES"
          print i + 1, j + 1
          return
      else:
        if vs[j] + rs[i] == total:
          print "YES"
          print i + 1, j + 1
          return
  print "NO"


if __name__ == '__main__':
  main()
