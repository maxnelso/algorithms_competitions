import itertools
import math

class LeftAndRightHandedDiv2:

  def count(self, S):
    out = 0
    for i in range(0, len(S) - 1):
      if S[i] == "R" and S[i + 1] == "L":
        out += 1
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "L" ], 0 ),
    ( [ "RRR" ], 0 ),
    ( [ "LRLRLR" ], 2 ),
    ( [ "LLLRRR" ], 0 ),
    ( [ "RLRLRL" ], 3 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        LeftAndRightHandedDiv2, 'count', TEST_CASES, isTestDisabled, 
        1475567981, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
