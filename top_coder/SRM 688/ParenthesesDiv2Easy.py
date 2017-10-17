import itertools
import math

class ParenthesesDiv2Easy:

  def getDepth(self, s):
    depth = 0
    current_depth = 0
    for c in s:
      if c == "(":
        current_depth += 1
        depth = max(depth, current_depth)
      else:
        current_depth -= 1
    return depth


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "(())" ], 2 ),
    ( [ "()()()" ], 1 ),
    ( [ "(())()" ], 2 ),
    ( [ "((())())(((())(()))())" ], 4 ),
    ( [ "()" ], 1 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ParenthesesDiv2Easy, 'getDepth', TEST_CASES, isTestDisabled, 
        1472110764, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
