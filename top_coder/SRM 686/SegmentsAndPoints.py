import itertools
import math

class SegmentsAndPoints:

  def isPossible(self, p, l, r):
    seen = [False] * len(p)

    p = list(p)
    p.sort()

    for x in p:
      best = -1
      for i in range(len(l)):
        if x >= l[i] and x <= r[i] and not seen[i]:
          if best == -1 or r[best] > r[i]:
            best = i
      if best == -1:
        return "Impossible"
      seen[best] = True
    return "Possible"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,), (0,0,), (1,3,) ], "Possible" ),
    ( [ (0,), (2,), (3,) ], "Impossible" ),
    ( [ (0,1,2,), (0,0,1,), (1,2,1,) ], "Possible" ),
    ( [ (0,1,), (-1,0,), (0,0,) ], "Impossible" ),
    ( [ (434,63,241,418,-380,-46,397,-205,-262,-282,260,-106,-389,-286,422,-75,127,382,52,-383,), (-447,-226,-411,287,-83,-228,-390,358,422,395,-461,-112,49,75,-160,-152,372,-447,-337,-362,), (-102,348,-70,466,168,-61,-389,469,433,471,-75,-41,52,236,299,-48,383,-353,346,-217,) ], "Possible" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SegmentsAndPoints, 'isPossible', TEST_CASES, isTestDisabled, 
        1472377352, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
