import math
from copy import copy, deepcopy
import itertools
import sys

FILENAME = 'A-test'

def is_good(grid):
  for i in range(len(grid)):
    for j in range(len(grid[0])):
      seen = {}
      seen[(i, j)] = True
      new_i = i
      new_j = j
      prev_d = (0, 0)
      while True:
        if grid[new_i][new_j] == '.':
          new_i += prev_d[0]
          new_j += prev_d[1]
        else:
          d = grid[new_i][new_j]
          if d == '^':
            new_i -= 1
            prev_d = (-1, 0)
          elif d == 'v':
            new_i += 1
            prev_d = (1, 0)
          elif d == '>':
            new_j += 1
            prev_d = (0, 1)
          elif d == '<':
            new_j -= 1
            prev_d = (0, -1)
        if (new_i, new_j) in seen:
          break
        seen[(new_i, new_j)] = True
        if new_j < 0 or new_j >= len(grid[0]) or new_i < 0 or new_i >= len(grid):
          return False
  return True


f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  r, c = map(int, f.readline().split())
  grid = []
  for i in range(r):
    grid.append(list(f.readline().strip()))
  arrows = []
  for i in range(r):
    for j in range(c):
      if grid[i][j] != '.':
        arrows.append((i, j))
  flag = False
  out = 'IMPOSSIBLE'
  if len(arrows) == 0:
    out = 0
  for k in range(len(arrows)):
    for combo in itertools.combinations(arrows, k):
      new_combos = []
      for c in combo:
        a = []
        a.append((c[0], c[1], '^'))
        a.append((c[0], c[1], '>'))
        a.append((c[0], c[1], 'v'))
        a.append((c[0], c[1], '<'))
        new_combos.append(a)
      for e in itertools.product(*new_combos):
        new_grid = [row[:] for row in grid]
        seen = {}
        bad = False
        for c in e:
          if (c[0], c[1]) in seen:
            bad = True
            break
          seen[(c[0], c[1])] = True
          new_grid[c[0]][c[1]] = c[2]
        if bad:
          continue
        if is_good(new_grid):
          flag = True
          break
      if flag:
        out = str(k)
        break
    if flag:
      out = str(k)
      break

  print 'Case #%d: %s' % (test, out)
