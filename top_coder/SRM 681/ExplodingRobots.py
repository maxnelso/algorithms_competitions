import itertools
import math

class ExplodingRobots:

  def canExplode(self, x1, y1, x2, y2, instructions):
    verts = 0
    horizs = 0
    for c in instructions:
      if c == "U" or c == "D":
        verts += 1
      else:
        horizs += 1
    x_diff = abs(x2 - x1)
    y_diff = abs(y2 - y1)
    if verts >= y_diff and horizs >= x_diff:
      return "Explosion"
    return "Safe"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 1, 0, 2, 0, "L" ], "Explosion" ),
    ( [ 1, 0, 2, 0, "U" ], "Safe" ),
    ( [ 1, 0, 2, 0, "UL" ], "Explosion" ),
    ( [ 3, 3, 5, 5, "LURLL" ], "Safe" ),
    ( [ 10, 5, -9, -10, "LULULULLLUULRULULULULULULLULULLULD" ], "Explosion" ),
    #Your custom test goes here:
    #( [ , , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ExplodingRobots, 'canExplode', TEST_CASES, isTestDisabled, 
        1473918748, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
