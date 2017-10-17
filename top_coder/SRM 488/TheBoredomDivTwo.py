import itertools
import math

class TheBoredomDivTwo:

  def find(self, n, m, j, b):
    j = j - 1
    b = b - 1
    total = n
    if j >= n:
      total += 1
    if b >= n:
      total += 1
    return total

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 1, 1, 1, 2 ], 2 ),
    ( [ 2, 1, 1, 2 ], 2 ),
    ( [ 1, 2, 3, 2 ], 3 ),
    ( [ 4, 7, 7, 4 ], 5 ),
    #Your custom test goes here:
    #( [ , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TheBoredomDivTwo, 'find', TEST_CASES, isTestDisabled, 
        1474772925, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
