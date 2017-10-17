import itertools
import math
import string

class Istr:

  def count(self, s, k):
    counts = [0] * 26
    for c in s:
      counts[string.lowercase.index(c)] += 1
    counts.sort()
    counts = counts[::-1]
    index = 0
    for i in range(k):
      max_index = 0
      m = 0
      for j in range(len(counts)):
        if counts[j] > m:
          m = counts[j]
          max_index = j
      counts[max_index] -= 1
    return sum(map(lambda x: x * x, counts))



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "aba", 1 ], 2 ),
    ( [ "abacaba", 0 ], 21 ),
    ( [ "abacaba", 1 ], 14 ),
    ( [ "abacaba", 3 ], 6 ),
    ( [ "abc", 3 ], 0 ),
    ( [ "wersrsresesrsesrawsdsw", 11 ], 23 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Istr, 'count', TEST_CASES, isTestDisabled, 
        1473143086, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
