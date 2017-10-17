import math
import sys

import math

def nCr(n,r):
  f = math.factorial
  return f(n) / f(r) / f(n-r)

def main():
  n = int(raw_input())
  xs = {}
  ys = {}
  points = []
  for i in range(n):
    x, y = map(int, raw_input().split())
    points.append((x, y))
    if x in xs:
      xs[x] += 1
    else:
      xs[x] = 1
    if y in ys:
      ys[y] += 1
    else:
      ys[y] = 1
  out = 0
  for i in range(len(points)):
    for j in range(i + 1, len(points)):
      p1 = points[i]
      p2 = points[j]
      print p1, p2, out
      # Run of the mill
      if p1[0] != p2[0] and p1[1] != p2[1]:
        out += n - 2
      elif p1[0] == p2[0] and p1[1] != p2[1]:
        out += n - xs[p1[0]]
      elif p1[0] != p2[0] and p1[1] == p2[1]:
        out += n - ys[p1[1]]
      else:
        print 'Should not happen'
      print p1, p2, out
  print out



if __name__ == '__main__':
  main()
