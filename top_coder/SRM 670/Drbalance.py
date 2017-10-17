import itertools
import math

class Drbalance:

  def check_balance(self, a):
    balance = 0
    out = 0
    for i in range(len(a)):
      if a[i] == '-':
        balance -= 1
      else:
        balance += 1
      out += balance < 0
    return out

  def lesscng(self, s, k):
    moves = 0
    s = list(s)
    index = 0
    while self.check_balance(s) > k:
      while s[index] != '-':
        index += 1
      s[index] = '+'
      moves += 1
    return moves



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "---", 1 ], 1 ),
    ( [ "+-+-", 0 ], 0 ),
    ( [ "-+-+---", 2 ], 1 ),
    ( [ "-------++", 3 ], 3 ),
    ( [ "-+--+--+--++++----+", 3 ], 2 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Drbalance, 'lesscng', TEST_CASES, isTestDisabled, 
        1477445016, 450, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
