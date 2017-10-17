import itertools
import math

class PackingBallsDiv2:

  def minPacks(self, R, G, B):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 4, 2, 4 ], 4 ),
    ( [ 1, 7, 1 ], 3 ),
    ( [ 2, 3, 5 ], 4 ),
    ( [ 78, 53, 64 ], 66 ),
    ( [ 100, 100, 100 ], 100 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PackingBallsDiv2, 'minPacks', TEST_CASES, isTestDisabled, 
        1474439799, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
