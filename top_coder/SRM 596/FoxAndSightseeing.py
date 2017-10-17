import itertools
import math

class FoxAndSightseeing:

  def getMin(self, position):
    best_dist = 100000000
    for i in range(len(position)):
      if i == 0 or i == len(position) - 1:
        continue
      dist = 0
      for j in range(len(position)):
        if j == i:
          continue
        if j == len(position) - 1:
          continue
        index = j + 1
        if index == i:
          index += 1
        dist += abs(position[j] - position[index])
      best_dist = min(best_dist, dist)

    return best_dist

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,4,-1,3,) ], 4 ),
    ( [ (-2,4,3,) ], 5 ),
    ( [ (1,2,3,4,5,6,7,8,9,10,) ], 9 ),
    ( [ (100,-100,99,-99,) ], 199 ),
    ( [ (74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38,) ], 836 ),
    ( [ (2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71,) ], 535 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FoxAndSightseeing, 'getMin', TEST_CASES, isTestDisabled, 
        1473982367, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
