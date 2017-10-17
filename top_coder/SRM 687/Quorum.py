import itertools
import math

class Quorum:

  def count(self, arr, k):
    a = list(arr)
    a.sort()
    return sum(a[:k])


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (5,2,3,), 1 ], 2 ),
    ( [ (1,1,1,1,1,), 5 ], 5 ),
    ( [ (50,2,9,49,38,), 3 ], 49 ),
    ( [ (20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,), 14 ], 105 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Quorum, 'count', TEST_CASES, isTestDisabled, 
        1472369643, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
