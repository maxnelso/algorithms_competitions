import itertools
import math

class DoubleWeights:

  def minimalCost(self, weight1, weight2):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ ("..14","..94","19..","44..",), ("..94","..14","91..","44..",) ], 64 ),
    ( [ ("..14","..14","11..","44..",), ("..94","..94","99..","44..",) ], 36 ),
    ( [ ("..","..",), ("..","..",) ], -1 ),
    ( [ (".....9","..9...",".9.9..","..9.9.","...9.9","9...9.",), (".....9","..9...",".9.9..","..9.9.","...9.9","9...9.",) ], 2025 ),
    ( [ (".4...1","4.1...",".1.1..","..1.1.","...1.1","1...1.",), (".4...1","4.1...",".1.1..","..1.1.","...1.1","1...1.",) ], 16 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        DoubleWeights, 'minimalCost', TEST_CASES, isTestDisabled, 
        1472408566, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
