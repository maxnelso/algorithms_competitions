import itertools
import math

class AmebaDiv2:

  def simulate(self, X, A):
    for x in X:
      if x == A:
        A = A * 2
    return A

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (2,1,3,1,2,), 1 ], 4 ),
    ( [ (1,4,9,16,25,36,49,), 10 ], 10 ),
    ( [ (1,2,4,8,16,32,64,128,256,1024,2048,), 1 ], 512 ),
    ( [ (817,832,817,832,126,817,63,63,126,817,832,287,823,817,574,), 63 ], 252 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        AmebaDiv2, 'simulate', TEST_CASES, isTestDisabled, 
        1474933184, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
