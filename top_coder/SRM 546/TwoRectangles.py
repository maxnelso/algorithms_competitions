import itertools
import math

class TwoRectangles:

  def describeIntersection(self, A, B):
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (0,0,3,2,), (1,1,5,3,) ], "rectangle" ),
    ( [ (0,0,5,3,), (1,2,2,3,) ], "rectangle" ),
    ( [ (1,1,6,2,), (3,2,5,4,) ], "segment" ),
    ( [ (0,1,2,3,), (2,0,5,2,) ], "segment" ),
    ( [ (0,0,1,1,), (1,1,5,2,) ], "point" ),
    ( [ (1,1,2,2,), (3,1,4,2,) ], "none" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TwoRectangles, 'describeIntersection', TEST_CASES, isTestDisabled, 
        1476674739, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
