import itertools
import math
import Queue

class IncubatorEasy:

  def helper(self, choice, love):
    protected = [False] * len(love)
    magical = [False] * len(love)
    seen = [False] * len(love)
    for c in choice:
      magical[c] = True
      q = Queue.Queue()
      q.put(c)
      while not q.empty():
        index = q.get()
        for i in range(len(love[index])):
          if love[index][i] == 'N':
            continue
          if seen[i]:
            continue
          seen[i] = True
          protected[i] = True
          q.put(i)
    out = 0
    for i in range(len(love)):
      if magical[i] and not protected[i]:
        out += 1
    return out

  def maxMagicalGirls(self, love):
    best = 0
    for i in range(1, len(love) + 1):
      eles = [list(x) for x in itertools.combinations(range(len(love)), i)]
      for choice in eles:
        best = max(best, self.helper(choice, love))
    return best


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("NY","NN",) ], 1 ),
    ( [ ("NYN","NNY","NNN",) ], 1 ),
    ( [ ("NNYNN","NNYNN","NNNYY","NNNNN","NNNNN",) ], 2 ),
    ( [ ("NNNNN","NYNNN","NYNYN","YNYNN","NNNNN",) ], 2 ),
    ( [ ("NNNNN","NNNNN","NNNNN","NNNNN","NNNNN",) ], 5 ),
    ( [ ("Y",) ], 0 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        IncubatorEasy, 'maxMagicalGirls', TEST_CASES, isTestDisabled, 
        1475533876, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
