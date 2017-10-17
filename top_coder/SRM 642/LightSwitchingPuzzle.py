import itertools
import math

class LightSwitchingPuzzle:

  def minFlips(self, state):
    state = list(state)
    flips = 0
    for i in range(len(state)):
      if state[i] == 'Y':
        for j in range(i, len(state), i + 1):
          if state[j] == 'Y':
            state[j] = 'N'
          else:
            state[j] = 'Y'
        flips += 1
    return flips

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "YYYYYY" ], 1 ),
    ( [ "YNYNYNYNY" ], 2 ),
    ( [ "NNNNNNNNNN" ], 0 ),
    ( [ "YYYNYYYNYYYNYYNYYYYN" ], 4 ),
    ( [ "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY" ], 12 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        LightSwitchingPuzzle, 'minFlips', TEST_CASES, isTestDisabled, 
        1476593761, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
