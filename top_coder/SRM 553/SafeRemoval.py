import itertools
import math

class SafeRemoval:

  def removeThem(self, seq, k):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (3,8,4,), 1 ], 11 ),
    ( [ (1,1,1,1,1,1,), 3 ], -1 ),
    ( [ (1,6,1,10,1,2,7,11,), 6 ], 21 ),
    ( [ (1,1,1,1,1,1,1,1,7,), 3 ], 6 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SafeRemoval, 'removeThem', TEST_CASES, isTestDisabled, 
        1476836406, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
