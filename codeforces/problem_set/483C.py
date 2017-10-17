import math

n, k = map(int, raw_input().split())

nums = range(1, n + 1)
left = 0
right = len(nums) - 1
left_start = True
print nums[left],
left += 1
left_start = False
while k != 1:
  if left_start:
    print nums[left],
    left += 1
    left_start = False
  else:
    print nums[right],
    right -= 1
    left_start = True
  k -= 1
if not left_start:
  while left <= right:
    print nums[left],
    left += 1

else:
  while right >= left:
    print nums[right],
    right -= 1
