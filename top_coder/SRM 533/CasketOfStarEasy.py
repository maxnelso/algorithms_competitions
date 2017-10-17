import itertools
import math

class CasketOfStarEasy:

  def helper(self, weights):
    if len(weights) <= 2:
      return 0
    best_score = 0
    for i in range(1, len(weights) - 1):
      new_weights = weights[:i] + weights[i+1:]
      best_score = max(best_score, self.helper(new_weights) + weights[i-1] * weights[i+1])
    return best_score


  def maxEnergy(self, weight):
    return self.helper(weight)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,3,4,) ], 12 ),
    ( [ (100,2,1,3,100,) ], 10400 ),
    ( [ (2,2,7,6,90,5,9,) ], 1818 ),
    ( [ (477,744,474,777,447,747,777,474,) ], 2937051 ),
    ( [ (1,1,1,1,1,1,1,1,1,1,) ], 8 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CasketOfStarEasy, 'maxEnergy', TEST_CASES, isTestDisabled, 
        1475623681, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
