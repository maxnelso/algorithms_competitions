import itertools
import math

class Initials:

  def getInitials(self, name):
    out = ""
    for w in name.split():
      out += w[0]
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "john fitzgerald kennedy" ], "jfk" ),
    ( [ "single" ], "s" ),
    ( [ "looks good to me" ], "lgtm" ),
    ( [ "single round match" ], "srm" ),
    ( [ "a aa aaa aa a bbb bb b bb bbb" ], "aaaaabbbbb" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Initials, 'getInitials', TEST_CASES, isTestDisabled, 
        1475119988, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
