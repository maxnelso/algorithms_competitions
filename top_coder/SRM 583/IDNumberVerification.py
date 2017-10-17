import itertools
import math

class IDNumberVerification:

  def verify(self, id, regionCodes):
    return ""

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "441323200312060636", ("441323",) ], "Male" ),
    ( [ "62012319240507058X", ("620123",) ], "Female" ),
    ( [ "321669197204300886", ("610111","659004",) ], "Invalid" ),
    ( [ "230231198306900162", ("230231",) ], "Invalid" ),
    ( [ "341400198407260005", ("341400",) ], "Invalid" ),
    ( [ "520381193206090891", ("532922","520381",) ], "Invalid" ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        IDNumberVerification, 'verify', TEST_CASES, isTestDisabled, 
        1477521136, 550, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
