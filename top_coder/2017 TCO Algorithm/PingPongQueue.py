import itertools
import math

class PingPongQueue:

  def whoPlaysNext(self, skills, N, K):
    return ()

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,3,), 2, 2 ], (2,3,) ),
    ( [ (1,2,3,), 2, 4 ], (1,2,) ),
    ( [ (49,24,26,12,5,33,25,30,35,41,46,23,21,3,38,43,11,19,34,29,20,32,39,7,50,), 10, 399 ], (12,50,) ),
    ( [ (30,12,), 34, 80 ], (12,30,) ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PingPongQueue, 'whoPlaysNext', TEST_CASES, isTestDisabled, 
        1491062409, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
