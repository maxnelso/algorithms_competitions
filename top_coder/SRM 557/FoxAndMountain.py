import itertools
import math

class FoxAndMountain:

  memo = {}

  def helper(self, n, diff):
    print n, diff, self.memo
    if n == 0 and diff == 0:
      return 1
    elif n == 0 and diff != 0:
      return 0
    elif (n, diff) in self.memo:
      return self.memo[(n, diff)]

    out = 0
    if diff - 1 >= 0:
      out += self.helper(n - 1, diff - 1)
    out += self.helper(n - 1, diff + 1)

    self.memo[(n, diff)] = out
    return out


  def count(self, n, history):
    diff = 0
    for c in history:
      if c == 'U':
        diff += 1
      else:
        if diff == 0:
          return 0
        diff -= 1

    return self.helper(n - len(history), diff) % 1000000009

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    #( [ 4, "UUDD" ], 1 ),
    #( [ 4, "DUUD" ], 0 ),
    #( [ 4, "UU" ], 1 ),
    #( [ 49, "U" ], 0 ),
    #( [ 20, "UUUDUUU" ], 990 ),
    ( [ 6, "UDU" ], 2),
    #( [ 30, "DUDUDUDUDUDUDUDU" ], 3718 ),
    #( [ 50, "U" ], 946357703 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FoxAndMountain, 'count', TEST_CASES, isTestDisabled, 
        1475536338, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
