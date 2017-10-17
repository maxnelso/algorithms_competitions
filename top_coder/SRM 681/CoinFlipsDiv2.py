import itertools
import math

class CoinFlipsDiv2:

  def countCoins(self, state):
    count = 0
    for i in range(len(state)):
      diff = False
      if i > 0 and state[i - 1] != state[i]:
        diff = True
      elif i < len(state) - 1 and state[i + 1] != state[i]:
        diff = True
      count += diff
    return count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "HT" ], 2 ),
    ( [ "T" ], 0 ),
    ( [ "HHH" ], 0 ),
    ( [ "HHTHHH" ], 3 ),
    ( [ "HHHTTTHHHTTTHTHTH" ], 12 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CoinFlipsDiv2, 'countCoins', TEST_CASES, isTestDisabled, 
        1473918513, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
