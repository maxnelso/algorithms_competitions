import itertools
import math

class RobotOnMoon:

  def longestSafeCommand(self, board):
    width = len(board[0])
    height = len(board)
    for i in range(height):
      for j in range(width):
        if board[i][j] == 'S':
          index = (j, i)
          break
    # NORTH
    for y in range(index[1], height):
      if board[y][index[0]] == '#':
        return - 1
    # SOUTH
    for y in range(index[1], -1, -1):
      if board[y][index[0]] == '#':
        return - 1
    # WEST
    for x in range(index[0], width):
      if board[index[1]][x] == '#':
        return -1
    # EAST
    for x in range(index[0], -1, -1):
      if board[index[1]][x] == '#':
        return -1
    west = index[0] - 0
    east = width - index[0] - 1
    north = height - index[1] - 1
    south = index[1] - 0
    return west + east + north + south

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("#####","#...#","#.S.#","#...#","#####",) ], -1 ),
    ( [ ("S......",) ], 6 ),
    ( [ ("#.######","#.#..S.#","#.#.##.#","#......#","########",) ], -1 ),
    ( [ ("S",) ], 0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        RobotOnMoon, 'longestSafeCommand', TEST_CASES, isTestDisabled, 
        1425145102, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
