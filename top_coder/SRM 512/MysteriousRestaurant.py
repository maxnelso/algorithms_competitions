import itertools
import math

class MysteriousRestaurant:

  def maxDays(self, prices, budget):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("26","14","72","39","32","85","06",), 13 ], 5 ),
    ( [ ("26","14","72","39","32","85","06","91",), 20 ], 8 ),
    ( [ ("SRM","512",), 4 ], 0 ),
    ( [ ("Dear","Code","rsHa","veFu","nInT","heCh","alle","ngeP","hase","andb","ecar","eful",), 256 ], 10 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MysteriousRestaurant, 'maxDays', TEST_CASES, isTestDisabled, 
        1477624188, 512, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
