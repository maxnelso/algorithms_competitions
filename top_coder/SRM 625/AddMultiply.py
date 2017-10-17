import itertools
import math

class AddMultiply:

  def makeExpression(self, y):
    for i in range(-1000, 1001):
      if i == 0 or i == 1:
        continue
      for j in range(-1000, 1001):
        if j == 0 or j == 1:
          continue
        x2 = y - (i * j)
        if x2 >= -1000 and x2 <= 1000 and x2 != 0 and x2 != 1:
          return (i, j, x2)
    return None


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 6 ], (2,2,2,) ),
    ( [ 11 ], (2,3,5,) ),
    ( [ 0 ], (7,10,-70,) ),
    ( [ 500 ], (-400,-3,-700,) ),
    ( [ 2 ], (2,2,-2,) ),
    ( [ 5 ], (5,2,-5,) ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        AddMultiply, 'makeExpression', TEST_CASES, isTestDisabled, 
        1475475610, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
