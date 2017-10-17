import itertools
import math

class Bracket107:

  def yetanother(self, s):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "(())" ], 1 ),
    ( [ "(())()" ], 3 ),
    ( [ "()()()" ], 3 ),
    ( [ "(((())))" ], 5 ),
    ( [ "((())())" ], 9 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Bracket107, 'yetanother', TEST_CASES, isTestDisabled, 
        1477446841, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
