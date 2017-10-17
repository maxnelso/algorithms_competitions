import itertools
import math

class SemiPerfectSquare:

  def check(self, N):
    for i in range(1, N):
      for j in range(1, i):
        if i * i * j == N:
          return "Yes"
    return "No"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 48 ], "Yes" ),
    ( [ 1000 ], "No" ),
    ( [ 25 ], "Yes" ),
    ( [ 47 ], "No" ),
    ( [ 847 ], "Yes" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SemiPerfectSquare, 'check', TEST_CASES, isTestDisabled, 
        1475370064, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
