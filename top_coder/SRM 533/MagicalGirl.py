import itertools
import math

class MagicalGirl:

  def maxExpectation(self, M, day, win, gain):
    return 0.0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 2, (1,), (75,), (1,) ], 2.5 ),
    ( [ 10, (5,5,5,5,), (100,100,100,100,), (1,1,1,1,) ], 14.0 ),
    ( [ 10, (5,5,5,5,5,), (40,80,60,20,0,), (10,10,10,10,10,) ], 13.0 ),
    ( [ 2, (2,), (100,), (2,) ], 2.0 ),
    ( [ 20, (2,13,8,7,9,4,6,21,), (18,83,75,23,45,23,10,98,), (10,9,8,10,7,16,13,20,) ], 35.908 ),
    ( [ 11, (10,20,30,40,50,60,70,80,90,), (100,100,100,100,100,100,100,100,100,), (10,10,10,10,10,10,10,10,10,) ], 101.0 ),
    ( [ 100000, (1000000,), (100,), (100000,) ], 100000.0 ),
    #Your custom test goes here:
    #( [ , , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MagicalGirl, 'maxExpectation', TEST_CASES, isTestDisabled, 
        1475625345, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
