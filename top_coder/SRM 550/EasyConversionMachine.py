import itertools
import math

class EasyConversionMachine:

  def isItPossible(self, originalWord, finalWord, k):
    inversions = 0
    for i in range(len(originalWord)):
      if originalWord[i] != finalWord[i]:
        inversions += 1
    if inversions <= k:
      if (k - inversions) % 2 == 0:
        return "POSSIBLE"
      return "IMPOSSIBLE"
    return "IMPOSSIBLE"

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "aababba", "bbbbbbb", 2 ], "IMPOSSIBLE" ),
    ( [ "aabb", "aabb", 1 ], "IMPOSSIBLE" ),
    ( [ "aaaaabaa", "bbbbbabb", 8 ], "POSSIBLE" ),
    ( [ "aaa", "bab", 4 ], "POSSIBLE" ),
    ( [ "aababbabaa", "abbbbaabab", 9 ], "IMPOSSIBLE" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        EasyConversionMachine, 'isItPossible', TEST_CASES, isTestDisabled, 
        1424221541, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
