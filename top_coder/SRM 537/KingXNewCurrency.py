import itertools
import math

class KingXNewCurrency:

  def isCombination(self, num, X, Y):
    for i in range(0, num / X + 1):
      if (num - i * X) % Y == 0:
        return True
    return False

  def howMany(self, A, B, X):
    if A % X == 0 and B % X == 0:
      return -1
    out = 0
    for i in range(1, max(A, B) + 1):
      if i != X and self.isCombination(A, X, i) and self.isCombination(B, X, i):
        out += 1
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 5, 8, 5 ], 5 ),
    ( [ 8, 4, 2 ], -1 ),
    ( [ 7, 4, 13 ], 1 ),
    ( [ 47, 74, 44 ], 2 ),
    ( [ 128, 96, 3 ], 65 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        KingXNewCurrency, 'howMany', TEST_CASES, isTestDisabled, 
        1476954734, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
