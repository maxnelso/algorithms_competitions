import itertools
import math

class FixedDiceGameDiv2:

  def getExpectation(self, a, b):
    out = 0
    total = 0
    for i in range(1, b + 1):
      size = a - i
      print i, size
      for j in range(i + 1, a + 1):
        total += 1
    for i in range(1, b + 1):
      size = a - i
      print i, size
      for j in range(i + 1, a + 1):
        out += j * (1.0 / total)
    return out


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 2 ], 2.0 ),
    ( [ 4, 2 ], 3.2 ),
    ( [ 3, 3 ], 2.6666666666666665 ),
    ( [ 11, 13 ], 7.999999999999999 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FixedDiceGameDiv2, 'getExpectation', TEST_CASES, isTestDisabled, 
        1476994786, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
