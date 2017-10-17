import math
import sys

def get_consecutive(row):
  best = 0
  current = 0
  for i in range(len(row)):
    if row[i] == 1:
      current += 1
    else:
      best = max(best, current)
      current = 0
  return max(best, current)

def main():
  n, m, q = map(int, raw_input().split())
  grid = []
  bests = []
  for i in range(n):
    row = map(int, raw_input().split())
    grid.append(row)
    bests.append(get_consecutive(row))
  for i in range(q):
    i, j = map(int, raw_input().split())
    i -= 1
    j -= 1
    if grid[i][j] == 0:
      grid[i][j] = 1
    else:
      grid[i][j] = 0
    bests[i] = get_consecutive(grid[i])
    current_best = 0
    for j in range(n):
      if bests[j] > current_best:
        current_best = bests[j]
    print current_best




if __name__ == '__main__':
  main()
