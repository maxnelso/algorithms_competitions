import itertools
import math

class MagicalSquare:

  def getCount(self, rowStrings, columnStrings):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("f","o","x",), ("f","o","x",) ], 1 ),
    ( [ ("x","x","x",), ("x","","xx",) ], 3 ),
    ( [ ("cd","cd","cd",), ("dvd","dvd","dvd",) ], 0 ),
    ( [ ("abab","ab","abab",), ("abab","ab","abab",) ], 11 ),
    ( [ ("qwer","asdf","zxcv",), ("qaz","wsx","erdfcv",) ], 1 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MagicalSquare, 'getCount', TEST_CASES, isTestDisabled, 
        1474245551, 950, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
