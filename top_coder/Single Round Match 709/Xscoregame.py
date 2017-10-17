import itertools
import math

class Xscoregame:

  def getscore(self, A):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,3,) ], 12 ),
    ( [ (10,0,0,0,) ], 80 ),
    ( [ (1,1,1,1,1,1,) ], 1 ),
    ( [ (1,0,1,0,1,0,1,0,) ], 170 ),
    ( [ (50,0,1,0,1,0,1,0,1,0,1,0,1,0,1,) ], 830122 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Xscoregame, 'getscore', TEST_CASES, isTestDisabled, 
        1487693145, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
