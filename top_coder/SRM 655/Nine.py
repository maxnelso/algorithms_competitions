import itertools
import math

class Nine:

  def count(self, N, d):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, (1,2,) ], 4 ),
    ( [ 2, (1,2,3,) ], 16 ),
    ( [ 1, (0,0,1,) ], 200 ),
    ( [ 5, (1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23,) ], 450877328 ),
    ( [ 5, (31,31,31,31,31,) ], 11112 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Nine, 'count', TEST_CASES, isTestDisabled, 
        1428593619, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
