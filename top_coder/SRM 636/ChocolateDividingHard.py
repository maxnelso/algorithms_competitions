import itertools
import math

class ChocolateDividingHard:

  def findBest(self, chocolate):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("95998","21945","23451","99798","74083",) ], 3 ),
    ( [ ("12942","23456","99798","98998","67675",) ], 5 ),
    ( [ ("129420","234560","997980","989980","676760",) ], 6 ),
    ( [ ("75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338",) ], 44 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ChocolateDividingHard, 'findBest', TEST_CASES, isTestDisabled, 
        1477109038, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
