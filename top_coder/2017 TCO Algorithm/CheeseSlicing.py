import itertools
import math

class CheeseSlicing:

  def totalArea(self, A, B, C, S):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 1, 3, 3, 2 ], 0 ),
    ( [ 5, 3, 5, 3 ], 25 ),
    ( [ 5, 5, 5, 2 ], 58 ),
    ( [ 49, 92, 20, 3 ], 30045 ),
    #Your custom test goes here:
    #( [ , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CheeseSlicing, 'totalArea', TEST_CASES, isTestDisabled, 
        1491063624, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
