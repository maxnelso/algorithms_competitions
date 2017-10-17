import math

memo = {}

n, s, l = map(int, raw_input().split())
nums = tuple(map(int, raw_input().split()))

def good(segment):
  return max(segment) - min(segment) <= s

def solve(nums, count):
  if nums in memo:
    return memo[nums]
  if len(nums) == 0:
    return count
  if len(nums) < l:
    return -1
  best = 100000000
  for i in range(l, len(nums) + 1):
    first = nums[:i]
    if good(first):
      total = solve(nums[i:], count + 1)
      if total != -1 and total < best:
        best = total
  if best == 100000000:
    best = -1
  memo[nums] = best
  return best

print solve(nums, 0)
