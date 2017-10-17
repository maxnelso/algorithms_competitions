import itertools
import math

class IncrementingSequence:

  def canItBeDone(self, k, A):
    marked = [False] * len(A)
    A = list(A)
    A.sort()
    N = len(A)
    print A
    for i in range(1, N + 1):
      found = False
      print i, marked
      for j in range(len(A)):
        if marked[j]:
          continue
        a = A[j]
        while a < i:
          a += k
        if a == i:
          marked[j] = True
          found = True
          break
      if not found:
        return "IMPOSSIBLE"
    return "POSSIBLE"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3, (1,2,4,3,) ], "POSSIBLE" ),
    ( [ 5, (2,2,) ], "IMPOSSIBLE" ),
    ( [ 1, (1,1,1,1,1,1,1,1,) ], "POSSIBLE" ),
    ( [ 2, (5,3,3,2,1,) ], "IMPOSSIBLE" ),
    ( [ 9, (1,2,3,1,4,5,6,7,9,8,) ], "POSSIBLE" ),
    ( [ 2, (1,1,1,1,1,1,2,2,2,2,2,2,) ], "POSSIBLE" ),
    ( [ 1, (1,) ], "POSSIBLE" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        IncrementingSequence, 'canItBeDone', TEST_CASES, isTestDisabled, 
        1475475889, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
