import itertools
import math

class Filtering:

  def designFilter(self, sizes, outcome):
    return ()

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (3,4,5,6,7,), "AAAAA" ], (3,7,) ),
    ( [ (3,4,5,6,7,), "AARAA" ], () ),
    ( [ (3,4,5,6,7,), "RAAAA" ], (4,7,) ),
    ( [ (68,57,7,41,76,53,43,77,84,52,34,48,27,75,36,), "RARRRARRRARARRR" ], (48,57,) ),
    ( [ (26,81,9,14,43,77,55,57,12,34,29,79,40,25,50,), "ARAAARRARARARAA" ], () ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Filtering, 'designFilter', TEST_CASES, isTestDisabled, 
        1474772607, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
