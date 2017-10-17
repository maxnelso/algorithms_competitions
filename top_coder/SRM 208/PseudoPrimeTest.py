import itertools
import math

class PseudoPrimeTest:

  def helper(self, i, q, mod):
    if q == 2:
      return (i * i) % mod
    if q == 3:
      return (i * i * i) % mod
    if q % 2 == 0:
      return (self.helper(i, q / 2, mod) ** 2) % mod
    else:
      return (i * (self.helper(i, q / 2, mod) ** 2)) % mod

  def firstFail(self, q):
    for i in range(2, q):
      if self.helper(i, q - 1, q) != 1:
        return i
    return q


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3 ], 3 ),
    ( [ 1729 ], 7 ),
    ( [ 561 ], 3 ),
    ( [ 7 ], 7 ),
    ( [ 341 ], 3 ),
    ( [ 31859 ], 31859 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PseudoPrimeTest, 'firstFail', TEST_CASES, isTestDisabled, 
        1474599754, 600, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
