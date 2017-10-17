import itertools
import math

class RainyRoad:

  def isReachable(self, road):
    for i in range(len(road[0])):
      if road[0][i] == "W" and road[1][i] == "W":
        return "NO"
    return "YES"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (".W..","....",) ], "YES" ),
    ( [ (".W..","..W.",) ], "YES" ),
    ( [ (".W..W..","...WWW.",) ], "NO" ),
    ( [ ("..","WW",) ], "YES" ),
    ( [ (".WWWW.","WWWWWW",) ], "NO" ),
    ( [ (".W.W.W.","W.W.W.W",) ], "YES" ),
    ( [ (".............................................W.",".............................................W.",) ], "NO" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        RainyRoad, 'isReachable', TEST_CASES, isTestDisabled, 
        1474235436, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
