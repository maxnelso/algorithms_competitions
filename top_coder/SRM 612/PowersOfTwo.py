import itertools
import math

class PowersOfTwo:

  def count(self, powers):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,2,) ], 4 ),
    ( [ (1,1,1,1,) ], 5 ),
    ( [ (1,2,2,2,4,4,16,) ], 32 ),
    ( [ (1,32,1,16,32,) ], 18 ),
    ( [ (1048576,1073741824,549755813888,70368744177664,4398046511104,262144,1048576,2097152,8796093022208,1048576,1048576,35184372088832,2097152,256,256,256,262144,1048576,1048576,70368744177664,262144,1048576,) ], 18432 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PowersOfTwo, 'count', TEST_CASES, isTestDisabled, 
        1475570865, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
