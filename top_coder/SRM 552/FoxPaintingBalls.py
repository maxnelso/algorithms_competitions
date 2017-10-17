import itertools
import math

class FoxPaintingBalls:

  def theMax(self, R, G, B, N):
    total = N * (N + 1) / 2
    ma = min(R / total, G / total, B / total)
    print ma
    count = 3 * ma
    R, G, B = R - ma * total, G - ma * total, B - ma * total
    print R, G, B, count
    third = total / 3
    mod = total % 3
    while True:
      a, b, c = sorted([R, G, B])
      print a, b, c
      if mod == 2:
        if c < third + 1:
          break
        c -= third + 1
        if b < third + 1:
          break
        b -= third + 1
        if a < third:
          break
        a -= third
      elif mod == 1:
        if c < third + 1:
          break
        c -= third + 1
        if b < third:
          break
        b -= third
        if a < third:
          break
        a -= third
      else:
        if c < third:
          break
        c -= third
        if b < third:
          break
        b -= third
        if a < third:
          break
        a -= third
      R, G, B = a, b, c
      print R, G, B
      count += 1
    return count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 2, 2, 3 ], 1 ),
    ( [ 1, 2, 3, 3 ], 0 ),
    ( [ 8, 6, 6, 4 ], 2 ),
    ( [ 7, 6, 7, 4 ], 2 ),
    ( [ 100, 100, 100, 4 ], 30 ),
    ( [ 949185738472857384, 819402738175983874, 905384829619493856, 4], 267397330626833511),
    ( [ 19330428391852493, 48815737582834113, 11451481019198930, 3456 ], 5750952686 ),
    ( [ 1, 1, 1, 1 ], 3 ),
    #Your custom test goes here:
    #( [ , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FoxPaintingBalls, 'theMax', TEST_CASES, isTestDisabled, 
        1476826026, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
