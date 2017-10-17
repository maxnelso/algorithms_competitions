import itertools
import math

class XMarksTheSpot:

  def countArea(self, board):
    L = 10000000
    R = 0
    B = 10000000
    T = 0
    questions = []
    index = 0
    for i in range(len(board)):
      for j in range(len(board[i])):
        if board[i][j] == 'O':
          L = min(L, j)
          R = max(R, j)
          B = min(B, i)
          T = max(T, i)
        elif board[i][j] == '?':
          questions.append((i, j))
    out = 0
    for i in range(1 << len(questions)):
      L_0 = L
      R_0 = R
      B_0 = B
      T_0 = T
      for j in range(len(questions)):
        if i >> j & 1:
          L_0 = min(questions[j][1], L_0)
          R_0 = max(questions[j][1], R_0)
          B_0 = min(questions[j][0], B_0)
          T_0 = max(questions[j][0], T_0)
      out += (R_0 - L_0 + 1) * (T_0 - B_0 + 1)
    return out


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("?.",".O",) ], 5 ),
    ( [ ("???","?O?","???",) ], 1952 ),
    ( [ ("...?.","?....",".O...","..?..","....?",) ], 221 ),
    ( [ ("OOOOOOOOOOOOOOOOOOOOO",) ], 21 ),
    ( [ ("?????????OO??????????",) ], 9963008 ),
    ( [ ("OOO","O?O","OOO","...",) ], 18 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        XMarksTheSpot, 'countArea', TEST_CASES, isTestDisabled, 
        1477456719, 450, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
