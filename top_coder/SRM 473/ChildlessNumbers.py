import itertools
import math

class ChildlessNumbers:

  def howMany(self, A, B):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 4, 7 ], 0 ),
    ( [ 37, 37 ], 0 ),
    ( [ 61, 65 ], 3 ),
    ( [ 275, 300 ], 1 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ChildlessNumbers, 'howMany', TEST_CASES, isTestDisabled, 
        1475376699, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
