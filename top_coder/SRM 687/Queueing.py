import itertools
import math

class Queueing:

  def probFirst(self, len1, len2, p1, p2):
    return 0.0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 1, 2, 2, 1 ], 0.5 ),
    ( [ 1, 3, 3, 7 ], 0.9835390946502058 ),
    ( [ 3, 1, 7, 3 ], 0.010973936899862834 ),
    ( [ 12, 34, 56, 78 ], 0.999996203228025 ),
    ( [ 3, 6, 8, 4 ], 0.5229465300297028 ),
    #Your custom test goes here:
    #( [ , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Queueing, 'probFirst', TEST_CASES, isTestDisabled, 
        1472371027, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
