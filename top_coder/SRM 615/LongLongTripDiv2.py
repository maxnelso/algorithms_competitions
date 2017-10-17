import itertools
import math

class LongLongTripDiv2:

  def isAble(self, D, T, B):
    y = float(D - T) / (B - 1)
    print y
    if y < 0:
      return "Impossible"
    if y % 1 != 0:
      return "Impossible"
    x = T - y
    if x < 0:
      return "Impossible"
    if x % 1 != 0:
      return "Impossible"
    return "Possible"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 10, 6, 3 ], "Possible" ),
    ( [ 10, 5, 3 ], "Impossible" ),
    ( [ 50, 100, 2 ], "Impossible" ),
    ( [ 120, 10, 11 ], "Impossible" ),
    ( [ 10, 10, 9999 ], "Possible" ),
    ( [ 1000, 100, 10 ], "Possible" ),
    ( [ 1000010000100001, 1100011, 1000000000 ], "Possible" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        LongLongTripDiv2, 'isAble', TEST_CASES, isTestDisabled, 
        1474933279, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
