import itertools
import math

class Xylophone:

  def countKeys(self, keys):
    notes = set()
    for c in keys:
      notes.add(c % 7)
    return len(notes)

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,8,3,) ], 2 ),
    ( [ (7,3,2,4,1,5,6,) ], 7 ),
    ( [ (1,8,15,) ], 1 ),
    ( [ (25,1,17,9,8,) ], 4 ),
    ( [ (11,11,11,11,11,11,11,11,11,11,11,) ], 1 ),
    ( [ (50,10,20,30,11,30,24,38,5,2,9,) ], 6 ),
    #Your custom test goes here:
    #( [ ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Xylophone, 'countKeys', TEST_CASES, isTestDisabled, 
        1477456599, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
