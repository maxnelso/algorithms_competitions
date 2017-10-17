import itertools
import math

class ParenthesesDiv2Medium:

  def correct(self, s):
    indices = []
    current_depth = 0
    for i in range(len(s)):
      c = s[i]
      if c == "(":
        current_depth += 1
      else:
        if current_depth == 0:
          current_depth += 1
          indices.append(i)
        else:
          current_depth -= 1
    current_index = len(s) - 1
    print indices, current_depth
    while current_depth != 0:
      if s[current_index] == "(":
        indices.append(current_index)
        current_depth -= 2
      current_index -= 1
    indices.sort()
    return tuple(indices)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ")(" ], (0,1,) ),
    ( [ ")))))(((((" ], (0,2,4,5,7,9,) ),
    ( [ "((()" ], (1,) ),
    ( [ ")))(()(())))))" ], (0,1,2,) ),
    ( [ "()()()()()()()()()()()()()" ], () ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ParenthesesDiv2Medium, 'correct', TEST_CASES, isTestDisabled, 
        1472110922, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
