import itertools
import math

class SubtreeSum:

  def getSum(self, p, x):


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (0,), (1,2,) ], 6 ),
    ( [ (0,1,), (1,2,4,) ], 23 ),
    ( [ (0,0,0,0,0,0,0,0,0,0,), (1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,1000000,) ], 33999993 ),
    ( [ (0,0,1,0,2,2,3,0,0,2,1,), (4,5,6,7,0,8,9,5,1,2,3,6,) ], 6378 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SubtreeSum, 'getSum', TEST_CASES, isTestDisabled, 
        1475126036, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
