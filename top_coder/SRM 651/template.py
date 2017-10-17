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

test = RobotOnMoon()


print test.longestSafeCommand(("S......",))
