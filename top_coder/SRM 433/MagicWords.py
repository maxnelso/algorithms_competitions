import itertools
import math

class MagicWords:

  def count(self, S, K):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("CAD","ABRA","ABRA",), 1 ], 6 ),
    ( [ ("AB","RAAB","RA",), 2 ], 3 ),
    ( [ ("AA","AA","AAA","A",), 1 ], 0 ),
    ( [ ("AA","AA","AAA","A","AAA","AAAA",), 15 ], 720 ),
    ( [ ("ABC","AB","ABC","CA",), 3 ], 0 ),
    ( [ ("A","B","C","A","B","C",), 1 ], 672 ),
    ( [ ("AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAB",), 1 ], 40320 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MagicWords, 'count', TEST_CASES, isTestDisabled, 
        1476397948, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
