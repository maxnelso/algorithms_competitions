import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  num_swaps = 0
  swaps = []
  for i in range(len(nums)):
    m = nums[i]
    index = i
    for j in range(i, len(nums)):
      if nums[j] < m:
        index = j
        m = nums[j]
    if index != i:
      nums[i], nums[index] = nums[index], nums[i]
      swaps.append('{0} {1}'.format(i, index))
      num_swaps += 1
  print num_swaps
  print '\n'.join(swaps)

if __name__ == '__main__':
  main()
