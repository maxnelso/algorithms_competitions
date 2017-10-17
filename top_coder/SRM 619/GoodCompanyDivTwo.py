import itertools
import math

class GoodCompanyDivTwo:

  def countGood(self, superior, workType):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (-1,0,), (1,2,) ], 2 ),
    ( [ (-1,0,), (1,1,) ], 1 ),
    ( [ (-1,0,1,1,), (1,4,3,2,) ], 4 ),
    ( [ (-1,0,1,0,0,), (3,3,5,2,2,) ], 4 ),
    ( [ (-1,0,1,1,1,0,2,5,), (1,1,2,3,4,5,3,3,) ], 7 ),
    ( [ (-1,0,0,1,1,3,0,2,0,5,2,5,5,6,1,2,11,12,10,4,7,16,10,9,12,18,15,23,20,7,4,), (4,6,4,7,7,1,2,8,1,7,2,4,2,9,11,1,10,11,4,6,11,7,2,8,9,9,10,10,9,8,8,) ], 27 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        GoodCompanyDivTwo, 'countGood', TEST_CASES, isTestDisabled, 
        1474409776, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
