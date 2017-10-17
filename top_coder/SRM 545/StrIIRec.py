import itertools
import math

class StrIIRec:

  def recovstr(self, n, minInv, minStr):
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, 1, "ab" ], "ba" ),
    ( [ 9, 1, "efcdgab" ], "efcdgabhi" ),
    ( [ 11, 55, "debgikjfc" ], "kjihgfedcba" ),
    ( [ 15, 0, "e" ], "eabcdfghijklmno" ),
    ( [ 9, 20, "fcdebiha" ], "fcdehigba" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        StrIIRec, 'recovstr', TEST_CASES, isTestDisabled, 
        1476672456, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
