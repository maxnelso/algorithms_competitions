import itertools
import math

class ConundrumReloaded:

  def minimumLiars(self, answers):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "LLH" ], 1 ),
    ( [ "?????" ], 0 ),
    ( [ "LHLH?" ], 2 ),
    ( [ "??LLLLLL??" ], 3 ),
    ( [ "LLL" ], -1 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ConundrumReloaded, 'minimumLiars', TEST_CASES, isTestDisabled, 
        1475477786, 950, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
