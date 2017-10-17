import itertools
import math

class SpaceWarDiv2:

  def minimalFatigue(self, magicalGirlStrength, enemyStrength, enemyCount):
    totalEnemies = []
    for i in range(len(enemyCount)):
      for j in range(enemyCount[i]):
        totalEnemies.append(enemyStrength[i])
    fatigues = [0] * len(magicalGirlStrength)
    totalEnemies.sort(reverse = True)
    for enemy in totalEnemies:
      bestGirlIndex = -1
      bestGirlFatigue = 1000000
      for i in range(len(magicalGirlStrength)):
        girl = magicalGirlStrength[i]
        if girl >= enemy and fatigues[i] < bestGirlFatigue:
          bestGirlFatigue = fatigues[i]
          bestGirlIndex = i
      if bestGirlIndex == -1:
        return -1
      fatigues[bestGirlIndex] += 1

    return max(fatigues)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (2,3,5,), (1,3,4,), (2,9,4,) ], 7 ),
    ( [ (2,3,5,), (1,1,2,), (2,9,4,) ], 5 ),
    ( [ (14,6,22,), (8,33,), (9,1,) ], -1 ),
    ( [ (17,10,29,48,92,60,80,100,15,69,36,43,70,14,88,12,14,29,9,40,), (93,59,27,68,48,82,15,95,61,49,68,15,16,26,64,82,7,8,92,15,), (56,26,12,52,5,19,93,36,69,61,68,66,55,28,49,55,63,57,33,45,) ], 92 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SpaceWarDiv2, 'minimalFatigue', TEST_CASES, isTestDisabled, 
        1475370219, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
