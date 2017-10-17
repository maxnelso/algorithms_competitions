import itertools
import math

class WinterAndReindeers:

  def getNumber(self, allA, allB, allC):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("X",), ("X","Y",), ("X",) ], 1 ),
    ( [ ("ABCXD",), ("BCDEF",), ("CD",) ], 3 ),
    ( [ ("WE","LOVE",), ("WORKING","FOR","SANTA",), ("JK",) ], 0 ),
    ( [ ("ABCDE",), ("CDEAB",), ("B",) ], 2 ),
    ( [ ("ABCABDEGAXAHDJBAAHFJDXBB","ABHFHCDALFDJDBBA","BABBAXAXXX",), ("ABLOCBAXBAHAJDXBIJKA","JBABCDAHKFIUDALPJAH","AABACX",), ("AXBADXBBAB","CDD",) ], 23 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        WinterAndReindeers, 'getNumber', TEST_CASES, isTestDisabled, 
        1477211380, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
