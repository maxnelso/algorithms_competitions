import itertools
import math

class FoxAndFlowerShopDivTwo:

  def theMaxFlowers(self, flowers, r, c):
    left, right, up, down = 0, 0, 0, 0
    for i in range(len(flowers)):
      for j in range(len(flowers[i])):
        if flowers[i][j] == 'F':
          if i < r:
            left += 1
          if i > r:
            right += 1
          if j < c:
            down += 1
          if j > c:
            up += 1
    return max(left, right, up, down)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("F.F",".F.",".F.",), 1, 1 ], 2 ),
    ( [ ("F..","...","...",), 0, 0 ], 0 ),
    ( [ (".FF.F.F","FF...F.","..FF.FF",), 1, 2 ], 6 ),
    ( [ ("F",".","F","F","F",".","F","F",), 4, 0 ], 3 ),
    ( [ (".FFF..F...","FFF...FF.F","..F.F.F.FF","FF..F.FFF.","..FFFFF...","F....FF...",".FF.FF..FF","..F.F.FFF.",".FF..F.F.F","F.FFF.FF.F",), 4, 3 ], 32 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FoxAndFlowerShopDivTwo, 'theMaxFlowers', TEST_CASES, isTestDisabled, 
        1476825739, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
