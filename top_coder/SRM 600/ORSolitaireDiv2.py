import itertools
import math

class ORSolitaireDiv2:

  def getMinimum(self, numbers, goal):
    strings = []
    for number in numbers:
      strings.append("{0:b}".format(number).zfill(32))
    goal = "{0:b}".format(goal).zfill(32)
    marked = [False] * len(numbers)
    for j in range(len(strings)):
      s = strings[j]
      for i in range(32):
        if goal[i] == '0' and s[i] == '1':
          marked[j] = True

    print strings, goal
    best = 1000000
    for i in range(32):
      if goal[i] == '1':
        count = 0
        for j in range(len(strings)):
          number = strings[j]
          if marked[j]:
            continue
          if number[i] == '1':
            count += 1
        best = min(best, count)
        print i, best
    return best


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,4,), 7 ], 1 ),
    ( [ (1,2,4,7,8,), 7 ], 2 ),
    ( [ (12571295,2174218,2015120,), 1 ], 0 ),
    ( [ (5,2,4,52,62,9,8,3,1,11,6,), 11 ], 3 ),
    ( [ (503,505,152,435,491,512,1023,355,510,500,502,255,63,508,509,511,60,250,254,346,), 510 ], 5 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ORSolitaireDiv2, 'getMinimum', TEST_CASES, isTestDisabled, 
        1476906811, 600, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
