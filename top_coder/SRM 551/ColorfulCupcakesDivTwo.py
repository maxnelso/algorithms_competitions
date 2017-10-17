import itertools
import math

class ColorfulCupcakesDivTwo:

  def countArrangements(self, cupcakes):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "ABAB" ], 2 ),
    ( [ "ABABA" ], 0 ),
    ( [ "ABC" ], 6 ),
    ( [ "ABABABABABABABABABABABABABABABABABABABABABABABABAB" ], 2 ),
    ( [ "BCBABBACBABABCCCCCAABBAACBBBBCBCAAA" ], 741380640 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ColorfulCupcakesDivTwo, 'countArrangements', TEST_CASES, isTestDisabled, 
        1476821806, 950, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
