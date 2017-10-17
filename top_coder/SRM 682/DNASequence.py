import itertools
import math

class DNASequence:

  def longestDNASequence(self, sequence):
    best_count = 0
    count = 0
    for c in sequence:
      if c == "A" or c == "C" or c == "T" or c == "G":
        count += 1
      else:
        count = 0
      best_count = max(count, best_count)
    return best_count

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "TOPBOATER" ], 2 ),
    ( [ "SUSHI" ], 0 ),
    ( [ "GATTACA" ], 7 ),
    ( [ "GOODLUCK" ], 1 ),
    ( [ "VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA" ], 6 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        DNASequence, 'longestDNASequence', TEST_CASES, isTestDisabled, 
        1473749559, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
