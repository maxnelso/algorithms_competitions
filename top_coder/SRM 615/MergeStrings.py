import itertools
import math

class MergeStrings:

  def getmin(self, S, A, B):
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "??CC??", "ABC", "BCC" ], "ABCCBC" ),
    ( [ "WHAT?", "THE", "WA" ], "" ),
    ( [ "PARROT", "PARROT", "" ], "PARROT" ),
    ( [ "???????????", "AZZAA", "AZAZZA" ], "AAZAZZAAZZA" ),
    ( [ "????K??????????????D???K???K????????K?????K???????", "KKKKKDKKKDKKDDKDDDKDKK", "KDKDDKKKDDKDDKKKDKDKKDDDDDDD" ], "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK" ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MergeStrings, 'getmin', TEST_CASES, isTestDisabled, 
        1474935823, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
