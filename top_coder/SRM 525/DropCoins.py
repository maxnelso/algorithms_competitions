import itertools
import math
import Queue


class DropCoins:

  def getMinimum(self, board, K):
    total = 0
    rows = []
    cols = []
    row_count = 0
    for row  in range(len(board)):
      for col in range(len(board[row])):
        if board[row][col] == "o":
          total += 1
    """
    col_count = 0
    for col in range(len(board[0])):
      for row  in range(len(board)):
        if board[row][col] == "o":
          col_count += 1
      cols.append(col_count)

    print rows, cols



    #for n in range(len(30)):
    #  for s in range(len(30)):
    #    for e in range(len(30)):
    #      for w in range(len(30)):
      """

    to_check = [(-1, len(board), -1, len(board[0]), 0)] # n, s, e, w, count
    best = -1
    while len(to_check) > 0:
      n, s, e, w, count  = to_check.pop()
      if total - count == K:
        if best == -1 or self.moves(n, s, e, w, board) < best:
          print n, s, e, w
          best = self.moves(n, s, e, w, board)
      if n + 1 < s and n + 1 < len(board):
        adding = 0
        for i in range(len(board[n + 1])):
          if i > e and i < w and board[n + 1][i] == "o":
            adding += 1

        to_check.append((n + 1, s, e, w, count + adding))

      if s - 1 > n and s - 1 >= 0:
        adding = 0
        for i in range(len(board[s - 1])):
          if i > e and i < w and board[s - 1][i] == "o":
            adding += 1

        to_check.append((n, s - 1, e, w, count + adding))

      if e + 1 < w and e + 1 < len(board[0]):
        adding = 0
        for i in range(len(board)):
          if i > n and i < s and board[i][e + 1] == "o":
            adding += 1

        to_check.append((n, s, e + 1, w, count + adding))

      if w - 1 < e and w - 1 >= 0:
        adding = 0
        for i in range(len(board)):
          if i > n and i < s and board[i][w - 1] == "o":
            adding += 1

        to_check.append((n, s, e, w - 1, count + adding))

    return best

  def moves(self, n, s, e, w, board):
    count = 0
    s_moves = len(board) - s
    n_moves = n + 1
    e_moves = e + 1
    w_moves = len(board[0]) - w
    count += min(n_moves, s_moves) * 2 + max(n_moves, s_moves)
    count += min(e_moves, w_moves) * 2 + max(e_moves, w_moves)
    return count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (".o..","oooo","..o.",), 3 ], 2 ),
    ( [ (".....o","......","oooooo","oooooo","......","o.....",), 12 ], 3 ),
    ( [ ("....",".oo.",".oo.","....",), 3 ], -1 ),
    ( [ (".......","..ooo..","ooooooo",".oo.oo.","oo...oo",), 12 ], 4 ),
    ( [ (".................",".ooooooo...oooo..",".ooooooo..oooooo.",".oo.......oo..oo.",".oo.......oo..oo.",".ooooo.....oooo..",".ooooooo...oooo..",".....ooo..oo..oo.","......oo..oo..oo.",".ooooooo..oooooo.",".oooooo....oooo..",".................",), 58 ], 6 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        DropCoins, 'getMinimum', TEST_CASES, isTestDisabled, 
        1474236047, 600, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
