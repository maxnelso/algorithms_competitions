import itertools
import math

class MagicalStringDiv2:

  def minimalMoves(self, S):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ">><<><" ], 2 ),
    ( [ ">>>><<<<" ], 0 ),
    ( [ "<<>>" ], 4 ),
    ( [ "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><" ], 20 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MagicalStringDiv2, 'minimalMoves', TEST_CASES, isTestDisabled, 
        1474439549, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
