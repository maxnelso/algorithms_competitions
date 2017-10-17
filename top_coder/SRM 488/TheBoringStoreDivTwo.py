import itertools
import math

class TheBoringStoreDivTwo:

  def find(self, J, B):
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "StoreOfJohn", "StoreOfBrus" ], "or" ),
    ( [ "JohnAndJohn", "John" ], "" ),
    ( [ "JohnPlaysGames", "BrusAlsoPlays" ], "ays" ),
    ( [ "abacaba", "abacabadabacaba" ], "abaabacaba" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TheBoringStoreDivTwo, 'find', TEST_CASES, isTestDisabled, 
        1474775981, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
