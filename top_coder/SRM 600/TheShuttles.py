import itertools
import math

class TheShuttles:

  def getLeastCost(self, cnt, baseCost, seatCost):
    best = 100000000
    for seats in range(1, 101):
      total = 0
      for c in cnt:
        total += math.ceil(float(c) / seats)
      best = min(best, total * (baseCost + seats * seatCost))
    return best



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (9,), 30, 5 ], 75 ),
    ( [ (9,4,), 30, 5 ], 150 ),
    ( [ (9,4,), 10, 5 ], 105 ),
    ( [ (51,1,77,14,17,10,80,), 32, 40 ], 12096 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TheShuttles, 'getLeastCost', TEST_CASES, isTestDisabled, 
        1476906089, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
