import itertools
import math
import heapq

class TallShoes:

  def binary_search(self, low, high, f):
    while low + 1 < high:
      mid = low + (high - low) / 2
      if f(mid):
        low = mid
      else:
        high = mid
    return low

  def maxHeight(self, N, X, Y, height, B):
    graph = [[] for _ in range(N)]
    for x, y, h in zip(X, Y, height):
      graph[x].append((y, h))
      graph[y].append((x, h))
    def possibleHeight(h):
      dist = [1000000000000000 for x in range(N)]
      dist[0] = 0
      Q = [(0, 0)]
      while Q:
        cost, v = heapq.heappop(Q)
        if dist[v] < cost:
          continue
        for (adj_v, adj_c) in graph[v]:
          c = max(0, h - adj_c)
          if dist[v] + c ** 2 < dist[adj_v]:
            dist[adj_v] = dist[v] + c**2
            heapq.heappush(Q, (dist[adj_v], adj_v))
      return dist[N-1] <= B

    return self.binary_search(0, 100000000000, possibleHeight)



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 12, (0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3), (1, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 6, 7, 8, 9, 7, 8, 9, 8, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11), (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1000000000000000 ], 1),
    ( [ 3, (0,1,0,), (1,2,2,), (3,4,2,), 1 ], 4 ),
    ( [ 3, (0,1,0,), (1,2,2,), (3,4,2,), 52 ], 9 ),
    ( [ 8, (0,0,3,3,4,4,4,7,7,), (1,2,1,2,3,5,6,5,6,), (1000,1000,1000,1000,1,1000,1000,1000,1000,), 3 ], 2 ),
    ( [ 10, (0,1,2,3,4,5,6,7,8,), (1,2,3,4,5,6,7,8,9,), (0,0,0,0,0,0,0,0,0,), 9876543210123 ], 1047565 ),
    ( [ 6, (0,0,0,0,0,1,1,1,1,2,2,2,3,3,4,), (1,2,3,4,5,2,3,4,5,3,4,5,4,5,5,), (999999,986588,976757,988569,977678,999999,967675,947856,955856,999999,975956,956687,999999,979687,999999,), 0 ], 999999 ),
    #Your custom test goes here:
    #( [ , , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TallShoes, 'maxHeight', TEST_CASES, isTestDisabled, 
        1476598924, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
