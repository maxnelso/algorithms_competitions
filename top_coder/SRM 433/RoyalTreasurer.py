import itertools
import math

class RoyalTreasurer:

  def minimalArrangement(self, A, B):
    A = list(A)
    B = list(B)
    A.sort()
    B.sort()
    out = 0
    for i in range(len(A)):
      out += A[i] * B[len(B) - i - 1]
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,1,3,), (10,30,20,) ], 80 ),
    ( [ (1,1,1,6,0,), (2,7,8,3,1,) ], 18 ),
    ( [ (5,15,100,31,39,0,0,3,26,), (11,12,13,2,3,4,5,9,1,) ], 528 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        RoyalTreasurer, 'minimalArrangement', TEST_CASES, isTestDisabled, 
        1476397743, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
