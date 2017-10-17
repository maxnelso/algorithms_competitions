import itertools
import math

class BracketSequenceDiv2:

  def count(self, s):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "(())(" ], 2 ),
    ( [ "())" ], 1 ),
    ( [ ")(((" ], 0 ),
    ( [ "()()()()()()()()(())))(()()()()))())" ], 364675 ),
    ( [ "()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()" ], 122826009 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BracketSequenceDiv2, 'count', TEST_CASES, isTestDisabled, 
        1472408057, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
