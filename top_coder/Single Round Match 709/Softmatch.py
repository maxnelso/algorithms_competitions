import itertools
import math

class Softmatch:

  def count(self, S, patterns):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "aaa", ("03","21",) ], 2 ),
    ( [ "aba", ("03","11",) ], 3 ),
    ( [ "bba", ("00","00",) ], 4 ),
    ( [ "bbbbbb", ("1110","011","100",) ], 3 ),
    ( [ "abbaa", ("123",) ], 2 ),
    ( [ "aababbaab", ("012","332","101","0313",) ], 7 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Softmatch, 'count', TEST_CASES, isTestDisabled, 
        1487694025, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
