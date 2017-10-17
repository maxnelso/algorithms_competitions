import itertools
import math

class ImageDithering:

  def count(self, dithered, screen):
    count = 0
    for i in range(len(screen)):
      for j in range(len(screen[i])):
        if screen[i][j] in dithered:
          count += 1
    return count


# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ "BW", ("AAAAAAAA","ABWBWBWA","AWBWBWBA","ABWBWBWA","AWBWBWBA","AAAAAAAA",) ], 24 ),
    ( [ "BW", ("BBBBBBBB","BBWBWBWB","BWBWBWBB","BBWBWBWB","BWBWBWBB","BBBBBBBB",) ], 48 ),
    ( [ "ACEGIKMOQSUWY", ("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX","ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX",) ], 150 ),
    ( [ "CA", ("BBBBBBB","BBBBBBB","BBBBBBB",) ], 0 ),
    ( [ "DCBA", ("ACBD",) ], 4 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        ImageDithering, 'count', TEST_CASES, isTestDisabled, 
        1474599457, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
