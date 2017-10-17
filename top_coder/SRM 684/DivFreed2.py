import itertools
import math

class DivFreed2:

  def count(self, n, k):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 2 ], 3 ),
    ( [ 9, 1 ], 1 ),
    ( [ 3, 3 ], 15 ),
    ( [ 1, 107 ], 107 ),
    ( [ 2, 10 ], 83 ),
    ( [ 2, 1234 ], 1515011 ),
    ( [ 3, 8 ], 326 ),
    ( [ 10, 100000 ], 526882214 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        DivFreed2, 'count', TEST_CASES, isTestDisabled, 
        1473143999, 600, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
