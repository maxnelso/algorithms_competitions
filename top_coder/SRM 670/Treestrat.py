import itertools
import math

class Treestrat:

  def roundcnt(self, tree, A, B):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (0,), (0,), (1,) ], 1 ),
    ( [ (0,1,), (1,), (2,) ], 2 ),
    ( [ (0,0,0,3,4,), (2,), (1,) ], 2 ),
    ( [ (0,0,0,3,4,2,), (1,), (6,) ], 5 ),
    ( [ (0,0,0,3,4,2,), (1,), (6,5,) ], 3 ),
    ( [ (0,0,0,3,4,2,), (4,1,), (3,6,) ], 2 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Treestrat, 'roundcnt', TEST_CASES, isTestDisabled, 
        1477445629, 1050, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
