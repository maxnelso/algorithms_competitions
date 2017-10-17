import itertools
import math

class EmoticonsDiv2:

  def helper(self, smiles):
    if smiles == 1:
      return 0
    divisors = [x for x in range(1, smiles) if smiles % x == 0]
    best = 100000
    for divisor in divisors:
      best = min(best, self.helper(divisor) + smiles / divisor)
    return best



  def printSmiles(self, smiles):
    return self.helper(smiles)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2 ], 2 ),
    ( [ 6 ], 5 ),
    ( [ 11 ], 11 ),
    ( [ 16 ], 8 ),
    ( [ 1000 ], 21 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        EmoticonsDiv2, 'printSmiles', TEST_CASES, isTestDisabled, 
        1475569565, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
