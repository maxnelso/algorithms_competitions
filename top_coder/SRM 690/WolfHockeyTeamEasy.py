import itertools
import math

class WolfHockeyTeamEasy:

  def count(self, N, K):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 0 ], 12 ),
    ( [ 4, 5 ], 1104 ),
    ( [ 100, 120 ], 803057135 ),
    ( [ 234, 467 ], 0 ),
    ( [ 810, 893 ], 281618909 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        WolfHockeyTeamEasy, 'count', TEST_CASES, isTestDisabled, 
        1472024207, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
