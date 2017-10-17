import itertools
import math

class SquareScores:

  def calcexpectation(self, p, s):
    return 0.0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,99,), "aaaba" ], 8.0 ),
    ( [ (10,20,70,), "aa?bbbb" ], 15.0 ),
    ( [ (10,20,30,40,), "a??c?dc?b" ], 11.117 ),
    ( [ (25,25,21,2,2,25,), "a??b???????ff??e" ], 21.68512690712425 ),
    ( [ (4,4,4,3,4,4,4,4,4,4,3,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,), "??????????????????????????????" ], 31.16931963781721 ),
    ( [ (4,3,4,3,8,2,4,3,4,4,3,2,4,4,3,4,2,4,7,6,4,4,3,4,4,3,), "makigotapresentfromniko" ], 23.0 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SquareScores, 'calcexpectation', TEST_CASES, isTestDisabled, 
        1427332425, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
