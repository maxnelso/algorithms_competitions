import itertools
import math

class Quacking:

  def quack(self, s):
    best_ducks = 0
    ducks = 0
    letters = {"q" : 0, "u" : 0, "a" : 0, "c" : 0, "k" : 0}
    for c in s:
      letters[c] += 1
      for a in "quack":
        if c == a:
          break
        if letters[c] > letters[a]:
          return -1
      if c == "q":
        ducks += 1
      elif c == "k":
        ducks -= 1
      best_ducks = max(ducks, best_ducks)
    blah = letters["q"]
    for a in "quack":
      if letters[a] != blah:
        return -1
    return best_ducks

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "quqacukqauackck" ], 2 ),
    ( [ "kcauq" ], -1 ),
    ( [ "quackquackquackquackquackquackquackquackquackquack" ], 1 ),
    ( [ "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk" ], 10 ),
    ( [ "quqaquuacakcqckkuaquckqauckack" ], 3 ),
    ( [ "quackqauckquack" ], -1 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Quacking, 'quack', TEST_CASES, isTestDisabled, 
        1472370045, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
