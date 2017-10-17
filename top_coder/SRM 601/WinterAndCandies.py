import itertools
import math

class WinterAndCandies:

  def getNumber(self, type):
    out = 0
    type = list(type)
    type.sort()
    for k in range(1, type[len(type) - 1] + 1):
      ways = 1
      for i in range(1, k + 1):
        count = 0
        for x in type:
          if x > i:
            break
          count += x == i
        ways *= count
      out += ways
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,3,2,) ], 3 ),
    ( [ (1,1,2,) ], 4 ),
    ( [ (1,3,2,5,7,4,5,4,) ], 9 ),
    ( [ (1,1,2,2,3,3,4,4,5,5,) ], 62 ),
    ( [ (2,) ], 0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        WinterAndCandies, 'getNumber', TEST_CASES, isTestDisabled, 
        1477210630, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
