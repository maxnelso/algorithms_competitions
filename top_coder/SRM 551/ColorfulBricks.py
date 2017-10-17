import itertools
import math

class ColorfulBricks:

  def countLayouts(self, bricks):
    chars = set()
    for c in bricks:
      chars.add(c)
    if len(chars) >= 3:
      return 0
    elif len(chars) == 2:
      return 2
    else:
      return 1


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "ABAB" ], 2 ),
    ( [ "AAA" ], 1 ),
    ( [ "WXYZ" ], 0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ColorfulBricks, 'countLayouts', TEST_CASES, isTestDisabled, 
        1476819313, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
