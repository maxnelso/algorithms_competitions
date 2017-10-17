import itertools
import math

class SubtreesCounting:

  def sumOfSizes(self, n, a0, b, c, m):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3, 1, 1, 1, 1 ], 10 ),
    ( [ 5, 1, 2, 3, 100 ], 52 ),
    ( [ 1, 1, 1, 1, 1 ], 1 ),
    ( [ 2, 5, 6, 7, 8 ], 4 ),
    ( [ 100000, 123, 46645, 4564579, 1000000000 ], 769840633 ),
    #Your custom test goes here:
    #( [ , , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SubtreesCounting, 'sumOfSizes', TEST_CASES, isTestDisabled, 
        1473581647, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
