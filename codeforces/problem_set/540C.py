import math
import sys

def check_dest(grid, dest, n, m):
  x, y = dest
  if grid[x][y] == 'X':
    return True
  # Top
  count = 0
  if x + 1 < n:
    if grid[x+1][y] == '.':
      count += 1
  if x - 1 >= 0:
    if grid[x-1][y] == '.':
      count += 1
  if y + 1 < m:
    if grid[x][y + 1] == '.':
      count += 1
  if y - 1 >= 0:
    if grid[x][y - 1] == '.':
      count += 1
  if count > 1:
    return True
  else:
    return False

def main():
  n, m = map(int, raw_input().split())
  grid = []
  for i in range(n):
    row = raw_input()
    grid.append(row)
  start = map(int, raw_input().split())
  start = tuple([start[0] - 1, start[1] - 1])
  dest = map(int, raw_input().split())
  dest = tuple([dest[0] - 1, dest[1] - 1])
  seen = set()
  stack = []
  stack.append(start)
  seen.add(start)
  while len(stack) > 0:
    node = stack.pop()
    x, y = node
    # Top
    if x + 1 < n:
      new_node = (x + 1, y)
      if new_node == dest:
        if check_dest(grid, dest, n, m):
          print 'YES'
          return
        else:
          print 'NO'
          return
      if new_node not in seen and grid[x + 1][y] == '.':
        seen.add(new_node)
        stack.append(new_node)

    # Bottom
    if x - 1 >= 0:
      new_node = (x - 1, y)
      if new_node == dest:
        if check_dest(grid, dest, n, m):
          print 'YES'
          return
        else:
          print 'NO'
          return
      if new_node not in seen and grid[x - 1][y] == '.':
        seen.add(new_node)
        stack.append(new_node)

    # Left
    if y - 1 >= 0:
      new_node = (x, y - 1)
      if new_node == dest:
        if check_dest(grid, dest, n, m):
          print 'YES'
          return
        else:
          print 'NO'
          return
      if new_node not in seen and grid[x][y - 1] == '.':
        seen.add(new_node)
        stack.append(new_node)

    # Right
    if y + 1 < m:
      new_node = (x, y + 1)
      if new_node == dest:
        if check_dest(grid, dest, n, m):
          print 'YES'
          return
        else:
          print 'NO'
          return
      if new_node not in seen and grid[x][y + 1] == '.':
        seen.add(new_node)
        stack.append(new_node)

  print 'NO'


if __name__ == '__main__':
  main()
