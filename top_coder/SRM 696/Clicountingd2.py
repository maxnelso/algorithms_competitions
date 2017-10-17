import itertools
import math

class Clicountingd2:

  def count(self, g):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("01","10",) ], 2 ),
    ( [ ("0?","?0",) ], 3 ),
    ( [ ("011","101","110",) ], 3 ),
    ( [ ("0?1","?01","110",) ], 5 ),
    ( [ ("0???","?0??","??0?","???0",) ], 151 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Clicountingd2, 'count', TEST_CASES, isTestDisabled, 
        1471933993, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
