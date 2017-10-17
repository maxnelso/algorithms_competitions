import itertools
import math

class BinPackingEasy:

  def minBins(self, item):
    start = 0
    end = len(item) - 1
    count = 0
    item = list(item)
    item.sort()
    while start <= end:
      a = item[start]
      b = item[end]
      print a, b, start, end
      while a + b > 300 and start != end:
        count += 1
        end -= 1
        b = item[end]
      if start == end:
        count += 1
        break
      else:
        count += 1
        start += 1
        end -= 1

    return count


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (150,150,150,150,150,) ], 3 ),
    ( [ (130,140,150,160,) ], 2 ),
    ( [ (101,101,101,101,101,101,101,101,101,) ], 5 ),
    ( [ (101,200,101,101,101,101,200,101,200,) ], 6 ),
    ( [ (123,145,167,213,245,267,289,132,154,176,198,) ], 8 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        BinPackingEasy, 'minBins', TEST_CASES, isTestDisabled, 
        1474865923, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
