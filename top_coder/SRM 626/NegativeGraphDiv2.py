import itertools
import math

class NegativeGraphDiv2:

  def findMin(self, N, s, t, weight, charges):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3, (1,1,2,2,3,3,), (2,3,1,3,1,2,), (1,5,1,10,1,1,), 1 ], -9 ),
    ( [ 1, (1,), (1,), (100,), 1000 ], -100000 ),
    ( [ 2, (1,1,2,), (2,2,1,), (6,1,4,), 2 ], -9 ),
    ( [ 2, (1,), (2,), (98765,), 100 ], -98765 ),
    #Your custom test goes here:
    #( [ , , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        NegativeGraphDiv2, 'findMin', TEST_CASES, isTestDisabled, 
        1476995920, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
