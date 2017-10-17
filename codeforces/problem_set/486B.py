import math

m, n = map(int, raw_input().split())
grid = []
for i in range(m):
  row = map(int, raw_input().split())
  grid.append(row)

def check(x, y):
  #up
  for i in range(0, x):
    if grid[i][y] == 0:
      return False
  #down
  for i in range(x + 1, m):
    if grid[i][y] == 0:
      return False
  #left
  for i in range(0, y):
    if grid[x][i] == 0:
      return False
  #right
  for i in range(y + 1, n):
    if grid[x][i] == 0:
      return False
  return True

out_grid = []
for i in range(m):
  row = [0] * n
  out_grid.append(row)

row_memo = [0] * m
col_memo = [0] * n
for i in range(m):
  for j in range(n):
    if grid[i][j] == 1:
      if not check(i, j):
        out_grid[i][j] = 0
      else:
        out_grid[i][j] = 1
        row_memo[i] = 1
        col_memo[j] = 1

for i in range(m):
  for j in range(n):
    if (row_memo[i] == 0 and col_memo[j] == 0) and grid[i][j] == 1:
      print "NO"
      exit()


print "YES"
for i in range(m):
  for j in range(n):
    print out_grid[i][j],
  print
