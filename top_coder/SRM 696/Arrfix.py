import itertools
import math

class Arrfix:

  def mindiff(self, A, B, F):
    A = list(A)
    B = list(B)
    F = list(F)
    out = 0
    for i in range(len(A)):
      if A[i] != B[i] and B[i] in F:
        F.remove(B[i])
      elif A[i] != B[i]:
        out += 1

    for i in range(len(A)):
      if A[i] == B[i] and B[i] in F:
        F.remove(A[i])

    print F
    if len(F) > 0 and len(F) > out:
      return len(F)
    return out

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (1,1,1,), (2,2,2,), (2,) ], 2 ),
    ( [ (1,1,1,), (2,2,1,), (2,2,) ], 0 ),
    ( [ (1,2,3,), (3,2,1,), () ], 2 ),
    ( [ (2,2,2,), (2,2,2,), (1,2,3,) ], 2 ),
    ( [ (882, 700, 4, 558, 999, 22, 713, 893, 882, 477, 76, 558, 893, 558, 390, 22, 601, 882, 323, 999), (870, 700, 511, 700, 870, 882, 893, 601, 390, 22, 558, 390, 511, 558, 511, 76, 652, 76, 882, 477), (601, 76, 601, 558, 477, 862, 862, 870, 558) ], 13),
    ( [ (1,3,3,3,), (2,3,3,3,), (2,2,) ], 1 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        Arrfix, 'mindiff', TEST_CASES, isTestDisabled, 
        1471931358, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
