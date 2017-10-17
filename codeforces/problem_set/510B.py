import math
import sys

def main():
  n, m = map(int, raw_input().split())
  grid = []
  for i in range(n):
    grid.append(raw_input())

  visited = []
  for i in range(100):
    row = []
    for j in range(100):
      row.append(False)
    visited.append(row)

  def dfs(x, y, last):
    visited[x][y] = True
    for d in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
      new_node = (x + d[0], y + d[1])
      if 0 <= new_node[0] < n and 0 <= new_node[1] < m and grid[new_node[0]][new_node[1]] == grid[x][y]:
        if visited[new_node[0]][new_node[1]] and new_node != last and last != None:
          print "Yes"
          exit()
        if not visited[new_node[0]][new_node[1]]:
          dfs(new_node[0], new_node[1], (x, y))
  for i in range(n):
    for j in range(m):
      dfs(i, j, None)
  print "No"


if __name__ == '__main__':
  main()
