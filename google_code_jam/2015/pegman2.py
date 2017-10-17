import math
import itertools
import sys

FILENAME = 'A-test'

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  r, c = map(int, f.readline().split())
  grid = []
  for i in range(r):
    grid.append(list(f.readline().strip()))
  # outside
  changes = 0
  for i in range(c):
    if grid[0][i] == '^':
      grid[0][i] = 'v'
      changes += 1
    elif grid[r - 1][i] == 'v':
      grid[r - 1][i] = '^'
      changes += 1
  for i in range(r):
    if grid[i][0] == '<':
      grid[i][0] = '>'
      changes += 1
    elif grid[i][c - 1] == '>':
      grid[i][c - 1] = '<'
      changes += 1
  for i in range(r):
    for j in range(c):
      if grid[i][j] != '.'

  print 'Case #%d: ' % (test,)
