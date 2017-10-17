import itertools
import math

class WinterAndMandarins:

  def getNumber(self, bags, K):
    bags = list(bags)
    bags.sort()
    diff = 100000000000
    for i in range(0, len(bags) - K + 1):
      diff = min(diff, bags[i + K - 1] - bags[i])
    return diff


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (10,20,30,), 2 ], 10 ),
    ( [ (4,7,4,), 3 ], 3 ),
    ( [ (4,1,2,3,), 3 ], 2 ),
    ( [ (5,4,6,1,9,4,2,7,5,6,), 4 ], 1 ),
    ( [ (47,1000000000,1,74,), 2 ], 27 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        WinterAndMandarins, 'getNumber', TEST_CASES, isTestDisabled, 
        1477210304, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
