import itertools
import math

class ANDEquation:

  def restoreY(self, A):
    for i in range(len(A)):
      start = ~0
      for j in range(len(A)):
        if j == i:
          continue
        start &= A[j]
      if start == A[i]:
        return A[i]
    return -1


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,3,5,) ], 1 ),
    ( [ (31,7,) ], -1 ),
    ( [ (31,7,7,) ], 7 ),
    ( [ (1,0,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,) ], 0 ),
    ( [ (191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,191411,191411,191411,) ], 191411 ),
    ( [ (1362,1066,1659,2010,1912,1720,1851,1593,1799,1805,1139,1493,1141,1163,1211,) ], -1 ),
    ( [ (2,3,7,19,) ], -1 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ANDEquation, 'restoreY', TEST_CASES, isTestDisabled, 
        1476671984, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
