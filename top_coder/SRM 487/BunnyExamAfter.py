import itertools
import math

class BunnyExamAfter:

  def getMaximum(self, black, gray, white):
    out = 0
    for i in range(len(black)):
      if gray[i] == white[i]:
        out += 2 * (gray[i] != black[i])
      else:
        out += gray[i] != black[i] or white[i] != black[i]
    return out


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "ABC", "ABC", "ABC" ], 0 ),
    ( [ "A", "B", "B" ], 2 ),
    ( [ "ABC", "PQR", "XYZ" ], 3 ),
    ( [ "AAAAA", "AABBB", "BBBAA" ], 6 ),
    ( [ "TOPCODER", "TOPBUNNY", "THEHONEY" ], 9 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BunnyExamAfter, 'getMaximum', TEST_CASES, isTestDisabled, 
        1477002467, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
