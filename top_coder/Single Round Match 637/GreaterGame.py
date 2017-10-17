import itertools
import math

class GreaterGame:

  def calc(self, hand, sothe):
    hand = list(hand)
    sothe = list(sothe)
    numbers = {}
    for i in range(2*len(hand)):
      numbers[i + 1] = True
    for num in hand:
      del numbers[num]
    up_against = []
    for num in sothe:
      if num != -1:
        del numbers[num]
        up_against.append(num)
    nums_left = list(numbers)
    out = 0.0
    hand.sort()
    up_against.sort()
    nums_left.sort()
    for num in up_against:
      found = False
      for i in range(len(hand)):
        if hand[i] > num:
          del hand[i]
          found = True
          out += 1.0
          break
      if not found:
        del hand[0]
    for num in hand:
      prob = 0.0
      for theirs in nums_left:
        if num > theirs:
          prob += 1.0 / len(nums_left)
      out += prob
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (4,2,), (-1,-1,) ], 1.5 ),
    ( [ (4,2,), (1,3,) ], 2.0 ),
    ( [ (2,), (-1,) ], 1.0 ),
    ( [ (1, 5, 6,), (-1,-1,-1) ], 2.0 ),
    ( [ (1,3,5,7,), (8,-1,4,-1,) ], 2.5 ),
    ( [ (6,12,17,14,20,8,16,7,2,15,), (-1,-1,4,-1,11,3,13,-1,-1,18,) ], 8.0 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        GreaterGame, 'calc', TEST_CASES, isTestDisabled, 
        1414077265, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
