import itertools
import math

class ContestWinner:

  def getWinner(self, events):
    m = {}
    for i in range(len(events)):
      a = events[i]
      if a in m:
        old = m[a][0]
        m[a] = (old + 1, i)
      else:
        m[a] = (1, i)
    best_time = 10000000
    best_contest = 0
    best_contestant = 0
    for contestant in m:
      contest, time = m[contestant]
      if contest > best_contest or (contest == best_contest and time < best_time):
        best_time = time
        best_contest = contest
        best_contestant = contestant
    return best_contestant

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (4,7,4,1,) ], 4 ),
    ( [ (10,20,30,40,50,) ], 10 ),
    ( [ (123,123,456,456,456,123,) ], 456 ),
    ( [ (1,2,2,3,3,3,4,4,4,4,) ], 4 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ContestWinner, 'getWinner', TEST_CASES, isTestDisabled, 
        1476674396, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
