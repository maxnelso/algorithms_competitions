import itertools
import math

class KingXNewBaby:

  def isValid(self, name):
    vowel = ''
    vowel_count = 0
    vowels = ['a', 'e', 'i', 'o', 'u']
    if len(name) != 8:
      return 'NO'
    for c in name:
      if c in vowels:
        if vowel == '':
          vowel = c
          vowel_count += 1
        elif vowel != c:
          return 'NO'
        else:
          vowel_count += 1
    if vowel_count != 2:
      return 'NO'
    return 'YES'

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "dengklek" ], "YES" ),
    ( [ "gofushar" ], "NO" ),
    ( [ "dolphinigle" ], "NO" ),
    ( [ "mystictc" ], "NO" ),
    ( [ "rngringo" ], "NO" ),
    ( [ "misof" ], "NO" ),
    ( [ "metelsky" ], "YES" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        KingXNewBaby, 'isValid', TEST_CASES, isTestDisabled, 
        1476954431, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
