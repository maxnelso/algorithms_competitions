import math
import sys

def main():
  n, m = map(int, raw_input().split())
  rows = n * [0]
  columns = n * [0]
  total = n * n
  total_rows = 0
  total_cols = 0
  for i in range(m):
    x, y = map(int, raw_input().split())
    if rows[x - 1] == 1 and columns[y - 1] == 1:
      pass
    elif rows[x - 1] == 1 and columns[y - 1] == 0:
      total -= (n - total_rows)
      total_cols += 1
    elif columns[y - 1] == 1 and rows[x - 1] == 0:
      total -= (n - total_cols)
      total_rows += 1
    else:
      total -= (n - total_rows) + (n - total_cols) -1
      total_rows += 1
      total_cols += 1
    rows[x - 1] = 1
    columns[y - 1] = 1
    print total,

if __name__ == '__main__':
  main()
