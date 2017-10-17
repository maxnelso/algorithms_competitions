import itertools
import math

class LineMSTDiv2:

  def count(self, N):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3 ], 15 ),
    ( [ 2 ], 2 ),
    ( [ 16 ], 682141922 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        LineMSTDiv2, 'count', TEST_CASES, isTestDisabled, 
        1477351687, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
