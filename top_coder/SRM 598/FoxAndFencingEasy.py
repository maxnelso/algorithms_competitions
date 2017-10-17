import itertools
import math

class FoxAndFencingEasy:

  def WhoCanWin(self, mov1, mov2, d):
    if mov1 >= d:
      return "Ciel"
    if mov1 == mov2:
      return "Draw"
    elif mov1 > mov2:
      if mov1 >= mov2 * 2 + 1:
        return "Ciel"
      else:
        return "Draw"
    elif mov2 > mov1:
      if mov2 >= mov1 * 2 + 1:
        return "Liss"
      else:
        return "Draw"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 1, 58, 1 ], "Ciel" ),
    ( [ 100, 100, 100000000 ], "Draw" ),
    ( [ 100, 150, 100000000 ], "Draw" ),
    ( [ 100, 250, 100000000 ], "Liss" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FoxAndFencingEasy, 'WhoCanWin', TEST_CASES, isTestDisabled, 
        1474866857, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
