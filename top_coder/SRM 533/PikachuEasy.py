import itertools
import math

class PikachuEasy:

  def check(self, word):
    while word:
      start = word[0]
      if start == "p":
        print "sup", word[:2]
        if word[:2] != "pi":
          return "NO"
        word = word[2:]
      elif start == "k":
        if word[:2] != "ka":
          return "NO"
        word = word[2:]
      elif start == "c":
        if word[:3] != "chu":
          return "NO"
        word = word[3:]
      else:
        return "NO"
    return "YES"




# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "pikapi" ], "YES" ),
    ( [ "pipikachu" ], "YES" ),
    ( [ "pikaqiu" ], "NO" ),
    ( [ "topcoder" ], "NO" ),
    ( [ "piika" ], "NO" ),
    ( [ "chupikachupipichu" ], "YES" ),
    ( [ "pikapipachu" ], "NO" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PikachuEasy, 'check', TEST_CASES, isTestDisabled, 
        1475623353, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
