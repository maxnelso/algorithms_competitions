import itertools
import math

class ParenthesesDiv2Hard:

  def minSwaps(self, s, L, R):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ")(", (0,), (1,) ], 1 ),
    ( [ "(())", (0,2,), (1,3,) ], 1 ),
    ( [ "(((())", (0,2,), (1,3,) ], 2 ),
    ( [ "(((((((((", (0,2,), (1,3,) ], -1 ),
    ( [ "))()())((()()()()()())))((((((", (1,6,13,17,23,25,), (4,7,16,20,24,28,) ], 5 ),
    ( [ "(", (0,), (0,) ], -1 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ParenthesesDiv2Hard, 'minSwaps', TEST_CASES, isTestDisabled, 
        1472112136, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
