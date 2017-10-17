import itertools
import math

class ColorfulChocolates:

  def maximumSpread(self, chocolates, maxSwaps):
    best = 0
    for center in range(len(chocolates)):
      swaps = maxSwaps
      on_left = 0
      on_right = 0
      for j in range(1, len(chocolates)):
        left = center - j
        if left >= 0 and swaps >= j - 1 - on_left:
          if chocolates[center] == chocolates[left]:
            swaps -= j - 1 - on_left
            on_left += 1
        right = center + j
        if right < len(chocolates) and swaps >= j - 1 - on_right:
          if chocolates[center] == chocolates[right]:
            swaps -= j - 1 - on_right
            on_right += 1
      best = max(best, on_left + on_right + 1)
    return best

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "ABCDCBC", 1 ], 2 ),
    ( [ "ABCDCBC", 2 ], 3 ),
    ( [ "ABBABABBA", 3 ], 4 ),
    ( [ "ABBABABBA", 4 ], 5 ),
    ( [ "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO", 77 ], 5 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ColorfulChocolates, 'maximumSpread', TEST_CASES, isTestDisabled, 
        1476819712, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
