import itertools
import math

class BichromePainting:

  def isThatPossible(self, board, k):
    for i in range(len(board)):
      for j in range(len(board)):


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("BBBW","BWWW","BWWW","WWWW",), 3 ], "Possible" ),
    ( [ ("BW","WB",), 2 ], "Impossible" ),
    ( [ ("BWBWBB","WBWBBB","BWBWBB","WBWBBB","BBBBBB","BBBBBB",), 2 ], "Possible" ),
    ( [ ("BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB",), 2 ], "Impossible" ),
    ( [ ("BWBWBB","WBWBWB","BWBWBB","WBWBWB","BWBWBB","BBBBBB",), 1 ], "Possible" ),
    ( [ ("BB","BB",), 2 ], "Possible" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BichromePainting, 'isThatPossible', TEST_CASES, isTestDisabled, 
        1428591608, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
