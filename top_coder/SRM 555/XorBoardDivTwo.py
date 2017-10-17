import itertools
import math

class XorBoardDivTwo:

  def theMax(self, board):
    best = 0
    for i in range(len(board)):
      for j in range(len(board[i])):
        best = max(best, self.flipAndScore(board, i, j))
    return best



  def flipAndScore(self, board, row, col):
    score = 0
    for i in range(len(board)):
      for j in range(len(board[i])):
        if i == row and j == col:
          score += board[i][j] == "1"
        elif i == row and j != col:
          score += board[i][j] == "0"
        elif i != row and j == col:
          score += board[i][j] == "0"
        else:
          score += board[i][j] == "1"
    return score

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("101","010","101",) ], 9 ),
    ( [ ("111","111","111",) ], 5 ),
    ( [ ("0101001","1101011",) ], 9 ),
    ( [ ("000","001","010","011","100","101","110","111",) ], 15 ),
    ( [ ("000000000000000000000000","011111100111111001111110","010000000100000001000000","010000000100000001000000","010000000100000001000000","011111100111111001111110","000000100000001000000010","000000100000001000000010","000000100000001000000010","011111100111111001111110","000000000000000000000000",) ], 105 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        XorBoardDivTwo, 'theMax', TEST_CASES, isTestDisabled, 
        1474317988, 255, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
