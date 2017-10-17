import itertools
import math

class Cdgame:

  def rescount(self, a, b):
    sum_a = sum(a)
    sum_b = sum(b)
    seen = set()
    for i in range(len(a)):
      for j in range(len(b)):
        seen.add((sum_a - a[i] + b[j]) * (sum_b + a[i] - b[j]))
    return len(seen)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,), (3,4,) ], 2 ),
    ( [ (1,2,4,), (8,16,32,) ], 9 ),
    ( [ (1,1,1,), (1,1,1,) ], 1 ),
    ( [ (1,2,3,), (5,5,5,) ], 3 ),
    ( [ (3,3,4,1,), (2,2,2,100,) ], 4 ),
    ( [ (31,34,55,56,57,), (1,2,3,4,5,) ], 15 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Cdgame, 'rescount', TEST_CASES, isTestDisabled, 
        1477444693, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
