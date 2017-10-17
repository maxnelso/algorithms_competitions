import itertools
import math

class Suminator:

  def findMissing(self, program, wantedResult):
    stack = []
    # Test 0
    for i in range(len(program)):
      if program[i] == 0 or program[i] == -1:
        if len(stack) < 2:
          while len(stack) != 2:
            stack.append((False, 0))
        a, b = stack.pop(), stack.pop()
        stack.append((a[0] or b[0], a[1] + b[1]))
      else:
        stack.append((False, program[i]))
    if len(stack) > 0 and stack.pop()[1] == wantedResult:
      print 'here'
      return 0

    stack = []
    used_wild = False
    for i in range(len(program)):
      if program[i] == 0:
        if len(stack) < 2:
          while len(stack) != 2:
            stack.append((False, 0))
        a, b = stack.pop(), stack.pop()
        stack.append((a[0] or b[0], a[1] + b[1]))
      elif program[i] == -1:
        stack.append((True, 0))
      else:
        stack.append((False, program[i]))
    if len(stack) == 0:
      return -1
    a = stack.pop()
    print a
    if not a[0] and a[1] == wantedResult:
      return 0
    elif not a[0] and a[1] != wantedResult:
      return -1
    else:
      print wantedResult, a[1]
      if wantedResult - a[1] <= 0:
        return -1
      return wantedResult - a[1]

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (7,-1,0,), 10 ], 3 ),
    ( [ (100,200,300,0,100,-1,), 600 ], 0 ),
    ( [ (-1,7,3,0,1,2,0,0,), 13 ], 0 ),
    ( [ (-1,8,4,0,1,2,0,0,), 16 ], -1 ),
    ( [ (1000000000,1000000000,1000000000,1000000000,-1,0,0,0,0,), 1000000000 ], -1 ),
    ( [ (7,-1,3,0,), 3 ], -1 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Suminator, 'findMissing', TEST_CASES, isTestDisabled, 
        1476832368, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
