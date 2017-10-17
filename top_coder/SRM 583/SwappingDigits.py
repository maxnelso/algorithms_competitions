import itertools
import math

class SwappingDigits:

  def minNumber(self, num):
    smallest = int(num)
    for i in range(len(num)):
      for j in range(i + 1, len(num)):
        new_num = list(num)
        tmp = new_num[i]
        new_num[i] = new_num[j]
        new_num[j] = tmp
        if new_num[0] == '0':
          continue
        smallest = min(smallest, int(''.join(new_num)))
    return smallest


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "596" ], "569" ),
    ( [ "93561" ], "13569" ),
    ( [ "5491727514" ], "1491727554" ),
    ( [ "10234" ], "10234" ),
    ( [ "93218910471211292416" ], "13218910471211292496" ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SwappingDigits, 'minNumber', TEST_CASES, isTestDisabled, 
        1477520633, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
