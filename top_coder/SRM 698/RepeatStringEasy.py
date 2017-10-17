import itertools
import math

class RepeatStringEasy:

  m = {}

  def helper(self, s1, s2, x, y):
    if (x, y) in self.m:
      return self.m[(x, y)]

    self.m[(x, y)] = 0
    if x >= 0:
      self.m[(x, y)] = max(self.m[(x, y)], self.helper(s1, s2, x - 1, y))
    if y >= 0:
      self.m[(x, y)] = max(self.m[(x, y)], self.helper(s1, s2, x, y - 1))
    if s1[x] == s2[y] and x >= 0 and y >= 0:
      self.m[(x, y)] = max(self.m[(x, y)], self.helper(s1, s2, x - 1, y - 1) + 2)
    return self.m[(x, y)]



  def maximalLength(self, s):
    out = 0
    for i in range(1, len(s)):
      self.m = {}
      self.m[(-1, -1)] = 0
      s1 = s[:i]
      s2 = s[i:]
      out = max(out, self.helper(s1, s2, len(s1) - 1, len(s2) - 1))

    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "frankfurt" ], 4 ),
    ( [ "single" ], 0 ),
    ( [ "singing" ], 6 ),
    ( [ "aababbababbabbbbabbabb" ], 18 ),
    #( [ "x" ], 0 ),
    ( [ "abab" ], 4 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        RepeatStringEasy, 'maximalLength', TEST_CASES, isTestDisabled, 
        1475120098, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
