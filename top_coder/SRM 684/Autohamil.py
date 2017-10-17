import itertools
import math
import Queue

class Autohamil:

  def check(self, z0, z1):
    n = len(z0)
    edges = [[]] * n

    for i in range(n):
      edges[i].append(z0[i])
      edges[i].append(z1[i])

    seen = set()
    queue = Queue.Queue()

    queue.put(0)
    seen.add(0)

    while not queue.empty():
      node = queue.get()

      for edge in edges[node]:
        if edge not in seen:
          seen.add(edge)
          queue.put(edge)


    if len(seen) == n:
      return "Exists"
    return "Does not exist"


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (0,1,), (0,1,) ], "Does not exist" ),
    ( [ (1,1,), (1,1,) ], "Exists" ),
    ( [ (1,2,2,), (2,2,2,) ], "Exists" ),
    ( [ (2,2,2,), (2,2,2,) ], "Does not exist" ),
    ( [ (1,2,0,3,), (3,2,0,3,) ], "Exists" ),
    ( [ (1,2,0,4,3,5,), (1,2,3,5,4,5,) ], "Exists" ),
    ( [ (1,2,0,4,4,5,), (1,2,3,5,4,5,) ], "Does not exist" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Autohamil, 'check', TEST_CASES, isTestDisabled, 
        1473145705, 900, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
