import itertools
import math

class MoveStonesEasy:

  def get(self, a, b):
    if sum(a) != sum(b):
      return -1

    a = list(a)
    b = list(b)
    count = 0
    for i in range(len(a)):
      diff = a[i] - b[i]
      print a, b
      if diff > 0:
        a[i+1] = a[i+1] + a[i] - b[i]
        count += a[i] - b[i]
      else:
        index = i + 1
        diff = abs(diff)
        while diff != 0:
          stones = a[index]
          dist = index - i
          print stones, diff
          if stones >= diff:
            leftover = stones - diff
            count += diff * dist
            diff = 0
            a[index] = leftover
          else:
            diff -= stones
            count += stones * dist
            a[index] = 0
          index += 1
    return count



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,), (2,1,) ], 1 ),
    ( [ (10,0,), (0,10,) ], 10 ),
    ( [ (0,0,1,), (1,0,0,) ], 2 ),
    ( [ (12,12,), (12,12,) ], 0 ),
    ( [ (5,), (6,) ], -1 ),
    #( [ (3,10,0,4,0,0,0,1,0,), (5,5,0,7,0,0,0,0,1,) ], 9 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MoveStonesEasy, 'get', TEST_CASES, isTestDisabled, 
        1473580119, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
