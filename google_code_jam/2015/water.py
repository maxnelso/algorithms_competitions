import math
from decimal import *
import itertools
import sys
import nose

FILENAME = 'B-small-attempt1'

getcontext().prec = 40
f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  n, v, temp = map(float, f.readline().split())
  n = int(n)
  v = Decimal(v)
  temp = Decimal(temp)
  out = 'IMPOSSIBLE'
  if n == 1:
    r, c = map(float, f.readline().split())
    r = Decimal(r)
    c = Decimal(c)
    if c == temp:
      out = v / r
  else:
    r1, c1 = map(float, f.readline().split())
    r1 = Decimal(r1)
    c1 = Decimal(c1)
    r2, c2 = map(float, f.readline().split())
    r2 = Decimal(r2)
    c2 = Decimal(c2)
    if c1 > temp and c2 > temp:
      out = 'IMPOSSIBLE'
    elif c1 < temp and c2 < temp:
      out = 'IMPOSSIBLE'
    elif c1 == c2:
      if c1 == temp:
        out = min(v / r1, v / r2)
      else:
        out = 'IMPOSSIBLE'
    else:
      volume1 = (temp * v - (v * c2)) / (c1 - c2)
      volume2 = (temp * v - (v * c1)) / (c2 - c1)
      out = max(volume1 / r1, volume2 / r2)


  if out == 'IMPOSSIBLE':
    print 'Case #%d: IMPOSSIBLE' % (test + 1,)
  else:
    print 'Case #%d: %.9f' % (test + 1, out)
