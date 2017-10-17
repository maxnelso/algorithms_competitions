import itertools
import math

class SumOfPower:

  def findSum(self, array):
    out = 0
    for i in range(len(array)):
      for j in range(i, len(array)):
        out += sum(array[i:j+1])
    return out


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,) ], 6 ),
    ( [ (1,1,1,) ], 10 ),
    ( [ (3,14,15,92,65,) ], 1323 ),
    ( [ (1,2,3,4,5,6,7,8,9,10,) ], 1210 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SumOfPower, 'findSum', TEST_CASES, isTestDisabled, 
        1476994581, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
