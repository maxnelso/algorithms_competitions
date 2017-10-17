import itertools
import math

class ForgetfulAddition:

  def minNumber(self, expression):
    n = len(expression)
    if n % 2 == 0:
      return int(expression[:n/2]) + int(expression[n/2:])
    else:
      return min(int(expression[:n/2 + 1]) + int(expression[n/2 + 1:]), int(expression[:n/2]) + int(expression[n/2:]))

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "22" ], 4 ),
    ( [ "123" ], 15 ),
    ( [ "1289" ], 101 ),
    ( [ "31415926" ], 9067 ),
    ( [ "98765" ], 863 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ForgetfulAddition, 'minNumber', TEST_CASES, isTestDisabled, 
        1476593604, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
