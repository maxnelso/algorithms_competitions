import itertools
import math

class BracketExpressions:

  def helper(self, expression):
    a_diff = 0
    b_diff = 0
    c_diff = 0
    for i in range(len(expression)):
      if expression[i] == ')':
        if a_diff <= 0:
          return False
        a_diff -= 1
      elif expression[i] == '(':
        a_diff += 1
      elif expression[i] == ']':
        if b_diff <= 0:
          return False
        b_diff -= 1
      elif expression[i] == '[':
        b_diff += 1
      elif expression[i] == '}':
        if c_diff <= 0:
          return False
        c_diff -= 1
      elif expression[i] == '{':
        c_diff += 1
      else:
        possible = False
        possible = possible or self.helper(expression[:i] + '(' + expression[i+1:])
        possible = possible or self.helper(expression[:i] + ')' + expression[i+1:])
        possible = possible or self.helper(expression[:i] + '[' + expression[i+1:])
        possible = possible or self.helper(expression[:i] + ']' + expression[i+1:])
        possible = possible or self.helper(expression[:i] + '}' + expression[i+1:])
        possible = possible or self.helper(expression[:i] + '{' + expression[i+1:])
        return possible
    if a_diff == 0 and b_diff == 0 and c_diff == 0:
      return True
    return False


  def ifPossible(self, expression):
    if self.helper(expression):
      return "possible"
    return "impossible"


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "([]{})" ], "possible" ),
    ( [ "(())[]" ], "possible" ),
    ( [ "({])" ], "impossible" ),
    ( [ "[]X" ], "impossible" ),
    ( [ "[XX]" ], "possible" ),
    ( [ "([]X()[()]XX}[])X{{}}]" ], "possible" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BracketExpressions, 'ifPossible', TEST_CASES, isTestDisabled, 
        1475479916, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
