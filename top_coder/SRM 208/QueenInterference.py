import itertools
import math

class QueenInterference:

  first = True
  last_random = 0

  def random(self):
    if self.first:
      self.first = False
      self.last_random = 1
      return 1
    self.last_random = ((16807 * self.last_random) % 2147483647)
    return self.last_random

  def numSteps(self, n):
    queens = []
    for i in range(n):
      queens.append((i + 1, (self.random() % n) + 1))
    count = 0
    while True:
      reachable = self.reachable(queens)
      if len(reachable) == 0:
        return count
      count += 1
      random_col = (self.random() % len(reachable))
      column_counts = self.column_count(reachable[random_col] + 1, queens, n)
      smallest_columns = []
      smallest_column = 100000
      for i in range(len(column_counts)):
        count = column_counts[i]
        if count < smallest_column:
          smallest_columns = [i]
          smallest_column = count
        elif count == smallest_column:
          smallest_columns.append(i)
      if len(smallest_columns) > 1:
        random = (self.random() % len(smallest_columns))
        queens[reachable[random_col] - 1] = (queens[reachable[random_col] - 1][0], smallest_columns[random])
      else:
        queens[reachable[random_col] - 1] = (queens[reachable[random_col] - 1][0], smallest_columns[0])



  def column_count(self, col, queens, n):
    out = [0] * n
    for i in range(n):
      coord = (col, i + 1)
      for queen in queens:
        if queen[0] == coord[0]:
          out[i] += 1
          continue
        if queen[1] == coord[1]:
          out[i] += 1
          continue
        dX = abs(queen[0] - coord[0])
        dY = abs(queen[1] - coord[1])
        if dX == dY:
          out[i] += 1
          continue
    return out


  def reachable(self, queens):
    out = []
    for i in range(len(queens)):
      added = False
      for j in range(len(queens)):
        if i != j:
          # Same row
          if queens[i][1] == queens[j][1]:
            out.append(i)
            added = True
            break
          # Same col
          if queens[i][0] == queens[j][0]:
            out.append(i)
            added = True
            break
          dX = abs(queens[i][0] - queens[j][0])
          dY = abs(queens[i][1] - queens[j][1])
          # Same diag
          if dX == dY:
            out.append(i)
            added = True
            break
        if added:
          break
    return out






# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 5 ], 4 ),
    ( [ 7 ], 6 ),
    #( [ 19 ], 475 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        QueenInterference, 'numSteps', TEST_CASES, isTestDisabled, 
        1474601738, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
