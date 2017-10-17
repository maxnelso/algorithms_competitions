import itertools
import math

class SortishDiv2:

  def ways(self, sortedness, seq):
    nums = set(range(1, len(seq) + 1))
    for x in seq:
      if x in nums:
        nums.remove(x)
    total = 0
    for p in itertools.permutations(nums, len(nums)):
      index = 0
      seq_list = list(seq)
      for i in range(len(seq_list)):
        if seq_list[i] == 0:
          seq_list[i] = p[index]
          index += 1
      count = 0
      for i in range(len(seq_list)):
        for j in range(i + 1, len(seq_list)):
          if seq_list[i] < seq_list[j]:
            count += 1
      total += count == sortedness

    return total

# CUT begin
#-------------------------------------------------------------------------------
CASE_TIME_OUT = 2.0;

TEST_CASES = [
    ( [ 5, (4,0,0,2,0,) ], 2 ),
    ( [ 4, (0,0,0,0,) ], 5 ),
    ( [ 2, (1,3,2,) ], 1 ),
    ( [ 2, (1,2,0,5,0,0,) ], 0 ),
    #Your custom test goes here:
    #( [ , ], None ),
]

def isTestDisabled(i):
    return False

#-------------------------------------------------------------------------------
if __name__ == '__main__':
    import sys, tester
    tester.run_tests(
        SortishDiv2, 'ways', TEST_CASES, isTestDisabled, 
        1477092486, 500, CASE_TIME_OUT, tester.COMPACT_REPORT
    )
# CUT end
