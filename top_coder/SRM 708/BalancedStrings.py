import itertools
import math

class BalancedStrings:

  def findAny(self, N):
    return ()

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3 ], ("eertree","topcoder","arena",) ),
    ( [ 4 ], ("hello","little","polar","bear",) ),
    ( [ 5 ], ("abbbbbbbbbbbbczaaaaaao","c","zz","c","xxxyyyzvvv",) ),
    ( [ 1 ], ("kkkkkkkkkkkkkkkkkkk",) ),
    ( [ 10 ], ("asdflkjhsdfsfffkdhjfdlshlfds","pudelek","xo","xo","mnbvmnmbbr","plox","qqwwrrttyyy","you","are","awesome",) ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BalancedStrings, 'findAny', TEST_CASES, isTestDisabled, 
        1487661948, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
