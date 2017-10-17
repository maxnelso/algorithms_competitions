import itertools
import math
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class MuddyRoad2:
  def theCount(self, N, muddyCount):
    return self.mod(
        self.countMudsTouching(N, muddyCount) +
            self.countNoMudsTouching(N, muddyCount))

  def countMudsTouching(self, numTiles, mudTiles):
    if mudTiles < 2:
      return 0
    # Pick any configuration by choosing any mud tiles between the start and
    # end.
    totalConfigurations = self.nCr(numTiles - 2, mudTiles)
    # Start and end must be dry. Put a dry between each mud. The rest are free.
    # Scatter them around the mud tiles. These are the bad configurations.
    freeDryTiles = numTiles - mudTiles - 2 - (mudTiles - 1)
    badConfigurations = self.nCr(freeDryTiles + mudTiles, mudTiles)
    return totalConfigurations - badConfigurations

  def countNoMudsTouching(self, numTiles, mudTiles):
    dryTiles = numTiles - mudTiles
    if dryTiles < mudTiles + 1:
      return 0
    # Pick any configuration by partitioning dry tiles into (mudTiles + 1)
    # pieces.
    totalConfigurations, badConfigurations = self.numPartitions(dryTiles, mudTiles + 1, False)
    return totalConfigurations - badConfigurations

  def numPartitions(self, total, numPieces, avoidMultThree):
    ans1 = [None for i in range(total + 1)]
    ans2 = [None for i in range(total + 1)]
    for i in xrange(1, total + 1):
      ans1[i] = [0 for j in range(numPieces + 1)]
      ans1[i][1] = 0 if (avoidMultThree and i % 3 == 0) else 1
      ans2[i] = [0 for j in range(numPieces + 1)]
      ans2[i][1] = 0 if (avoidMultThree and i % 3 == 0) else 1
      for j in xrange(2, min(numPieces + 1, i + 1)):
        ansJ1 = 0
        ansJ2 = 0
        for k in xrange(1, i):
          ansJ1 += 0 if (False and (i - k) % 3 == 0) else ans1[k][j - 1]
          ansJ2 += 0 if (True and (i - k) % 3 == 0) else ans2[k][j - 1]
        ans1[i][j] = ansJ1
        ans2[i][j] = ansJ2
    return (ans1[total][numPieces], ans2[total][numPieces])

  def nCr(self, n, r):
    return math.factorial(n) / math.factorial(r) / math.factorial(n-r)

  def mod(self, n):
    return n % 555555555

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 5, 1 ], 2 ),
    ( [ 5, 2 ], 2 ),
    ( [ 10, 4 ], 65 ),
    ( [ 314, 78 ], 498142902 ),
    ( [ 555, 222 ], 541606281 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        MuddyRoad2, 'theCount', TEST_CASES, isTestDisabled, 
        1474319721, 955, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
