import itertools
import math

class SuccessiveSubtraction2:

  def calc(self, a, p, v):
    return ()

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,3,4,5,), (1,2,0,4,3,), (3,9,-10,5,1,) ], (10,16,5,5,2,) ),
    ( [ (-100,-100,-100,-100,-100,), (0,1,2,3,4,), (0,0,0,0,0,) ], (400,300,200,100,0,) ),
    ( [ (83,0,25,21,), (0,3,2,1,3,1,2,), (10,-90,33,52,-100,0,45,) ], (56,125,133,81,91,143,155,) ),
    ( [ (1,), (0,0,0,0,), (10,-10,100,-100,) ], (10,-10,100,-100,) ),
    ( [ (-11,-4,28,38,21,-29,-45,11,-58,-39,92,35,-56,-6,29,-2,61,10,-29,-63,), (19,5,3,10,4,18,5,2,0,15,), (-19,21,7,-66,38,-39,-22,24,-32,13,) ], (451,443,412,440,457,467,468,464,443,458,) ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SuccessiveSubtraction2, 'calc', TEST_CASES, isTestDisabled, 
        1427335095, 450, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end