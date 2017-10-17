import itertools
import math

class SubdividedSlimes:

  def needCut(self, S, M):


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3, 2 ], 1 ),
    ( [ 3, 3 ], 2 ),
    ( [ 3, 4 ], -1 ),
    ( [ 765, 271828 ], 14 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SubdividedSlimes, 'needCut', TEST_CASES, isTestDisabled, 
        1477337704, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
