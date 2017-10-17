import itertools
import math

class PlatypusDuckAndBeaver:

  def minimumAnimals(self, webbedFeet, duckBills, beaverTails):
    for i in range(beaverTails + 1): # Beavers
      beavers = i
      platypus = beaverTails - i
      ducks = duckBills - platypus
      if ducks < 0:
        continue
      if beavers * 4 + ducks * 2 + platypus * 4 == webbedFeet and \
         beavers + platypus == beaverTails and \
         platypus + ducks == duckBills:
        return beavers + platypus + ducks
    return 0



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 4, 1, 1 ], 1 ),
    ( [ 0, 0, 0 ], 0 ),
    ( [ 10, 2, 2 ], 3 ),
    ( [ 60, 10, 10 ], 20 ),
    ( [ 1000, 200, 200 ], 300 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        PlatypusDuckAndBeaver, 'minimumAnimals', TEST_CASES, isTestDisabled, 
        1476831987, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
