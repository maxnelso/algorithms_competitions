import itertools
import math

class CuttingBitString:

  powers = set()
  MAX = 100000

  def helper(self, S, index, count):
    if index == len(S):
      return count

    best = self.MAX
    for i in range(index, len(S)):
      if S[index:i+1] in self.powers:
        best = min(best, self.helper(S, i + 1, count + 1))
    return best


  def getmin(self, S):
    for i in range(100):
      self.powers.add("{0:b}".format(5**i))

    out = self.helper(S, 0, 0)
    if out == self.MAX:
      return -1
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "101101101" ], 3 ),
    ( [ "1111101" ], 1 ),
    ( [ "00000" ], -1 ),
    ( [ "110011011" ], 3 ),
    ( [ "1000101011" ], -1 ),
    ( [ "111011100110101100101110111" ], 5 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        CuttingBitString, 'getmin', TEST_CASES, isTestDisabled, 
        1474318444, 555, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
