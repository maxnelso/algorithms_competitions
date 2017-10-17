import itertools
import math

class GreatFairyWar:

  def minHP(self, dps, hp):
    count = 0
    for i in range(len(dps)):
      for j in range(i, len(dps)):
        count += dps[j] * hp[i]
    return count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,), (3,4,) ], 17 ),
    ( [ (1,1,1,1,1,1,1,1,1,1,), (1,1,1,1,1,1,1,1,1,1,) ], 55 ),
    ( [ (20,12,10,10,23,10,), (5,7,7,5,7,7,) ], 1767 ),
    ( [ (5,7,7,5,7,7,), (20,12,10,10,23,10,) ], 1998 ),
    ( [ (30,2,7,4,7,8,21,14,19,12,), (2,27,18,19,14,8,25,13,21,30,) ], 11029 ),
    ( [ (1,), (1,) ], 1 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        GreatFairyWar, 'minHP', TEST_CASES, isTestDisabled, 
        1475533623, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
