import itertools
import math

class PalindromeMatrixDiv2:

  def minChange(self, A, rowCount, columnCount):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("0000","1000","1100","1110",), 2, 2 ], 1 ),
    ( [ ("0000","1000","1100","1110",), 3, 2 ], 3 ),
    ( [ ("01","10",), 1, 1 ], 1 ),
    ( [ ("1110","0001",), 0, 0 ], 0 ),
    ( [ ("01010101","01010101","01010101","01010101","01010101","01010101","01010101","01010101",), 2, 2 ], 8 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PalindromeMatrixDiv2, 'minChange', TEST_CASES, isTestDisabled, 
        1476906683, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
