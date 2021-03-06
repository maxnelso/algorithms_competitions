import itertools
import math

class FriendlyRobot:

  def findMaximumReturns(self, instructions, changesAllowed):
    return 0

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "UULRRLLL", 1 ], 3 ),
    ( [ "ULDR", 0 ], 1 ),
    ( [ "ULDR", 2 ], 2 ),
    ( [ "ULDRRLRUDUDLURLUDRUDL", 4 ], 8 ),
    ( [ "LRLDRURDRDUDDDDRLLRUUDURURDRRDRULRDLLDDDDRLRRLLRRDDLRURLRULLLLLRRRDULRULULRLRDLLDDLLRDLUUDUURRULUDUDURULULLDRUDUUURRRURUULRLDLRRRDLLDLRDUULUURUDRURRLURLDLDDUUURRURRLRDLDDULLUDLUDULRDLDUURLUUUURRLRURRDLRRLLLRDRDUUUDRRRDLDRRUUDUDDUDDRLUDDULRURRDRUDLDLLLDLUDDRLURLDUDRUDDDDURLUUUDRLURDDDDLDDRDLUDDLDLURR", 47 ], 94 ),
    ( [ "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU", 300 ], 150 ),
    ( [ "UD", 1 ], 1 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        FriendlyRobot, 'findMaximumReturns', TEST_CASES, isTestDisabled, 
        1473750496, 1000, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
