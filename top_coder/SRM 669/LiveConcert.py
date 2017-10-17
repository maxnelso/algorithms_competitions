import itertools
import math

class LiveConcert:

  def maxHappiness(self, h, s):
    best = {}
    for i in range(len(s)):
      if s[i] not in best:
        best[s[i]] = h[i]
      else:
        best[s[i]] = max(best[s[i]], h[i])
    return sum(best.values())


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (10,5,6,7,1,2,), ("ciel","bessie","john","bessie","bessie","john",) ], 23 ),
    ( [ (3,3,4,3,3,), ("a","a","a","a","a",) ], 4 ),
    ( [ (1,2,3,4,5,6,7,8,9,10,100,), ("a","b","c","d","e","e","d","c","b","a","abcde",) ], 140 ),
    ( [ (100,), ("oyusop",) ], 100 ),
    ( [ (100,100,100,100,100,100,100,100,100,100,100,100,100,), ("haruka","chihaya","yayoi","iori","yukiho","makoto","ami","mami","azusa","miki","hibiki","takane","ritsuko",) ], 1300 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        LiveConcert, 'maxHappiness', TEST_CASES, isTestDisabled, 
        1477350719, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
