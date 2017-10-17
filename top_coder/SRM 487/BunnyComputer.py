import itertools
import math

class BunnyComputer:

  def subproblem(self, parts):
    s = sum(parts)
    if len(parts) % 2 == 0:
      return s
    else:
      smallest = 100000000000
      for i in range(len(parts)):
        if i % 2 == 0 and parts[i] < smallest:
          smallest = parts[i]
      return s - smallest


  def getMaximum(self, preference, k):
    out = 0
    n = len(preference)
    for i in range(n):
      if i >= k + 1:
        break
      part = []
      for j in range(i, n, k + 1):
        part.append(preference[j])
      out += self.subproblem(part)
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (3,1,4,1,5,9,2,6,), 2 ], 28 ),
    ( [ (3,1,4,1,5,9,2,6,), 1 ], 31 ),
    ( [ (1,2,3,4,5,6,), 3 ], 14 ),
    ( [ (487,2010,), 2 ], 0 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BunnyComputer, 'getMaximum', TEST_CASES, isTestDisabled, 
        1477002716, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
