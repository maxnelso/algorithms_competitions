import itertools
import math

class ColorfulRoad:

  def helper(self, index, road):
    if index == len(road) - 1:
      return 0
    color = road[index]
    next_color = ""
    if color == "R":
      next_color = "G"
    elif color == "G":
      next_color = "B"
    else:
      next_color = "R"
    best_cost = 1000000000
    for i in range(index + 1, len(road)):
      if road[i] == next_color:
        cost = (i - index) ** 2 + self.helper(i, road)
        best_cost = min(best_cost, cost)
    return best_cost


  def getMin(self, road):
    seen_green = False
    seen_blue = False
    for c in road:
      if c == "G":
        seen_green = True
      if c == "B" and seen_green:
        seen_blue = True
    if road[-1] == "R":
      if not seen_green or not seen_blue:
        return -1
    if road[-1] == "G":
      pass
    if road[-1] == "B":
      if not seen_green:
        return -1
    return self.helper(0, road)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "RGGGB" ], 8 ),
    ( [ "RGBRGBRGB" ], 8 ),
    ( [ "RBBGGGRR" ], -1 ),
    ( [ "RBRRBGGGBBBBR" ], 50 ),
    ( [ "RG" ], 1 ),
    ( [ "RBRGBGBGGBGRGGG" ], 52 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ColorfulRoad, 'getMin', TEST_CASES, isTestDisabled, 
        1473983726, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
