import itertools
import math

class SparseFactorialDiv2:

  def getCount(self, lo, hi, divisor):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 4, 8, 3 ], 3 ),
    ( [ 9, 11, 7 ], 1 ),
    ( [ 1, 1000000000000, 2 ], 999999999999 ),
    ( [ 16, 26, 11 ], 4 ),
    ( [ 10000, 20000, 997 ], 1211 ),
    ( [ 123456789, 987654321, 71 ], 438184668 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SparseFactorialDiv2, 'getCount', TEST_CASES, isTestDisabled, 
        1473986405, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
