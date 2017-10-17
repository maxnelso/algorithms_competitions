import itertools
import math

class CombiningSlimes:

  def maxMascots(self, a):
    a = list(a)
    a.sort()
    total = 0
    while len(a) != 1:
      total += a[0] * a[-1]
      new = a[0] + a[-1]
      a = a[1:len(a) - 1] + [new]
    return total

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (3,4,) ], 12 ),
    ( [ (2,2,2,) ], 12 ),
    ( [ (1,2,3,) ], 11 ),
    ( [ (3,1,2,) ], 11 ),
    ( [ (7,6,5,3,4,6,) ], 395 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CombiningSlimes, 'maxMascots', TEST_CASES, isTestDisabled, 
        1477351000, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
