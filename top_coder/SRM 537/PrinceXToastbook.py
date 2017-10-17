import itertools
import math

class PrinceXToastbook:

  def eat(self, prerequisite):
    return 0.0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (-1,0,) ], 1.5 ),
    ( [ (-1,0,1,) ], 1.6666666666666667 ),
    ( [ (1,-1,1,) ], 2.0 ),
    ( [ (1,0,) ], 0.0 ),
    ( [ (-1,-1,) ], 2.0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PrinceXToastbook, 'eat', TEST_CASES, isTestDisabled, 
        1476955802, 925, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
