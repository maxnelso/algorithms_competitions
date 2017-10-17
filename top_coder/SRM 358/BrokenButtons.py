import itertools
import math

class BrokenButtons:

  def minPresses(self, page, broken):
    broken = list(broken)
    broken.sort()
    if len(broken) == 10:
      return max(page - 100, 100 - page)
    dist_from_page = 10000
    for i in range(dist_from_page):
      possible = True
      for d in str(i):
        if d not in broken:
          possible = False
          continue
      if possible:
        dist_from_page = min(dist_from_page, abs(i - page))
    print dist_from_page


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 5457, (6,7,8,) ], 6 ),
    ( [ 100, (1,0,5,) ], 0 ),
    ( [ 14124, () ], 5 ),
    ( [ 1, (1,2,3,4,5,6,7,8,9,) ], 2 ),
    ( [ 80000, (8,9,) ], 2228 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BrokenButtons, 'minPresses', TEST_CASES, isTestDisabled, 
        1477624440, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
