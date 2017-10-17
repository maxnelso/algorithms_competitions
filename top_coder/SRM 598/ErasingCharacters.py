import itertools
import math

class ErasingCharacters:

  def simulate(self, s):
    while True:
      found = False
      for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
          found = True
          s = s[:i] + s[i + 2:]
          break

      if not found:
        break
    return s


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "cieeilll" ], "cl" ),
    ( [ "topcoder" ], "topcoder" ),
    ( [ "abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba" ], "" ),
    ( [ "bacaabaccbaaccabbcabbacabcbba" ], "bacbaca" ),
    ( [ "eel" ], "l" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ErasingCharacters, 'simulate', TEST_CASES, isTestDisabled, 
        1474865635, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
