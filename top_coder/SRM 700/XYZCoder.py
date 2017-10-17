import itertools
import math

class XYZCoder:

  def countWays(self, room, size):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 1 ], 2 ),
    ( [ 1, 2 ], 1 ),
    ( [ 2, 2 ], 4 ),
    ( [ 4, 5 ], 6840 ),
    ( [ 100, 100 ], 718243627 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        XYZCoder, 'countWays', TEST_CASES, isTestDisabled, 
        1477459414, 900, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
