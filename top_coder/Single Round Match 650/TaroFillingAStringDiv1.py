import itertools
import math

class TaroFillingAStringDiv1:

  def getNumber(self, N, position, value):
    s = ['.'] * N
    for i in range(len(position)):
      s[position[i] - 1] = value[i]
    index = 0
    MOD = 1000000007
    out = 1
    print s
    while index < N:
      if s[index] == '.':
        if index == 0:
          while s[index] == '.':
            index += 1
          out *= 1
        else:
          prev = s[index - 1]
          count = 0
          # TODO ends
          while s[index] == '.':
            index += 1
            count += 1
            if index == N:
              out *= 1
              return out % MOD
          next = s[index]
          print count, prev, next, out
          if count == 1:
            if next == prev:
              out *= 1
            else:
              out *= 2
          elif count % 2 == 0:
            if next != prev:
              out *= 1
            else:
              out *= (count + 1)
              out = out % MOD
          else:
            if next != prev:
              out *= (count + 1)
              out = out % MOD
            else:
              out *= 1
      index += 1
    return out



# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 3, (1,3,), "AB" ], 2 ),
    ( [ 4, (2,1,3,4,), "ABBA" ], 1 ),
    ( [ 25, (23,4,8,1,24,9,16,17,6,2,25,15,14,7,13,), "ABBBBABABBAAABA" ], 1 ),
    ( [ 305, (183,115,250,1,188,193,163,221,144,191,92,192,58,215,157,187,227,177,206,15,272,232,49,11,178,59,189,246,), "ABAABBABBAABABBBBAAAABBABBBA" ], 43068480 ),
    #Your custom test goes here:
    #( [ , , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        TaroFillingAStringDiv1, 'getNumber', TEST_CASES, isTestDisabled, 
        1424224802, 250, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
