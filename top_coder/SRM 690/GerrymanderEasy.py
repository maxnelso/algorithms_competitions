import itertools
import math

class GerrymanderEasy:

  def getmax(self, A, B, K):
    total_sums = [0]
    like_sums = [0]
    total_sum = 0
    like_sum = 0
    for i in range(len(A)):
      total_sum += A[i]
      like_sum += B[i]
      total_sums.append(total_sum)
      like_sums.append(like_sum)
    print total_sums, like_sums
    best = 0
    for i in range(len(A) - K + 1):
      for j in range(K, len(A) + 1):
        print i, j
        if i + j > len(A):
          continue
        total_sum = total_sums[i + j] - total_sums[i]
        like_sum = like_sums[i + j] - like_sums[i]
        if like_sum > 0:
          best = max(float(like_sum) / total_sum, best)
    return best

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ (5,1,2,7,), (4,0,2,2,), 2 ], 0.75 ),
    ( [ (1,), (1,), 1 ], 1.0 ),
    ( [ (12,34,56,78,90,), (1,1,1,1,1,), 1 ], 0.08333333333333333 ),
    ( [ (10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,), (3,1,4,1,5,9,2,6,5,3,), 5 ], 5.4E-4 ),
    ( [ (123,4,46,88,22,34,564,87,56,311,886,), (0,0,0,0,0,0,0,0,0,0,0,), 1 ], 0.0 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        GerrymanderEasy, 'getmax', TEST_CASES, isTestDisabled, 
        1472022566, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
