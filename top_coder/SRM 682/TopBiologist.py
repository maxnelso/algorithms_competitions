import itertools
import math

class TopBiologist:

  def sequences_helper(self, length, current):
    if len(current) == length:
      return [current]

    return self.sequences_helper(length, current + "A") + self.sequences_helper(length, current + "C") + self.sequences_helper(length, current + "T") + self.sequences_helper(length, current + "G")


  def sequences(self, length):
    return self.sequences_helper(length, "")


  def findShortestNewSequence(self, sequence):
    for i in range(1, 10):
      s = self.sequences(i)
      for x in s:
        if x not in sequence:
          return x
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "AGGTCTA" ], "AC" ),
    ( [ "AGACGACGGAGAACGA" ], "T" ),
    ( [ "A" ], "C" ),
    ( [ "AAGATACACCGGCTTCGTG" ], "CAT" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TopBiologist, 'findShortestNewSequence', TEST_CASES, isTestDisabled, 
        1473749554, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
