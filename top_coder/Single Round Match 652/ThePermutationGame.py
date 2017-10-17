from fractions import gcd
import itertools
import math

class ThePermutationGame:

  def lcm(self, a, b):
    return a * b / gcd(a, b)

  def findMin(self, N):
    return reduce(self.lcm, range(1, N + 1)) % 1000000007

  def rangeLCM(self, last):
    factors = range(last+1)
    result = 1
    for n in range(1, last+1):
      print factors
      if factors[n] > 1:
        result *= factors[n]
        for j in range(2*n, last+1, n):
          factors[j] /= factors[n]
    return result


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2 ], 2 ),
    ( [ 3 ], 6 ),
    ( [ 11 ], 27720 ),
    ( [ 102 ], 53580071),
    ( [ 99999], 53580071),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ThePermutationGame, 'findMin', TEST_CASES, isTestDisabled, 
        1425913208, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
