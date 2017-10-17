import itertools
import math

class ColorTheCells:

  def minimalTime(self, dryingTime):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (2,2,3,) ], 6 ),
    ( [ (1,2,100,1,) ], 7 ),
    ( [ (33,58,21,44,) ], 26 ),
    ( [ (35198,26281,72533,91031,44326,43178,85530,) ], 26287 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ColorTheCells, 'minimalTime', TEST_CASES, isTestDisabled, 
        1475371215, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
