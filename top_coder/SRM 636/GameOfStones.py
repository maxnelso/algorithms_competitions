import itertools
import math

class GameOfStones:

  def count(self, stones):
    if len(stones) == 1:
      return 0
    total = sum(stones)
    per_pile = total / len(stones)
    if total % len(stones) != 0:
      return - 1
    out = 0
    for i in range(len(stones)):
      diff = abs(stones[i] - per_pile)
      print diff, per_pile
      if diff % 2 == 1:
        return -1
      out += diff / 2
    return out / 2

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (7,15,9,5,) ], 3 ),
    ( [ (10,16,) ], -1 ),
    ( [ (2,8,4,) ], -1 ),
    ( [ (17,) ], 0 ),
    ( [ (10,15,20,12,1,20,) ], -1 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        GameOfStones, 'count', TEST_CASES, isTestDisabled, 
        1477091935, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
