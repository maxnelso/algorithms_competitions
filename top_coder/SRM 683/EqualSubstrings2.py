import itertools
import math

class EqualSubstrings2:

  def get(self, s):
    count = 0
    for i in range(len(s)):
      for j in range(i, len(s)):
        length = j - i + 1
        sub1 = s[i:j + 1]
        for k in range(j + 1, len(s) - length + 1):
          sub2 = s[k:k + length]
          if sub2 == sub1:
            count += 1
    return count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "aa" ], 1 ),
    ( [ "abcd" ], 0 ),
    ( [ "aba" ], 1 ),
    ( [ "abab" ], 3 ),
    ( [ "aaaab" ], 7 ),
    ( [ "onetwothreeonetwothree" ], 86 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        EqualSubstrings2, 'get', TEST_CASES, isTestDisabled, 
        1473579580, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
