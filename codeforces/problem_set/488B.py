import math

def mean(nums):
  return sum(nums) / 4.0

def median(nums):
  return (nums[1] + nums[2]) / 2.0

def r(nums):
  return nums[3] - nums[0]

def good(nums):
  return mean(nums) == median(nums) and mean(nums) == r(nums)

n = int(raw_input())
nums = []
for i in range(n):
  nums.append(int(raw_input()))
nums = sorted(nums)
if len(nums) == 0:
  print "YES"
  print 1
  print 1
  print 3
  print 3
elif len(nums) == 1:
  print "YES"
  print nums[0]
  print nums[0] + 2 * nums[0]
  print nums[0] + 2 * nums[0]
elif len(nums) == 4:
  if good(nums):
    print "YES"
  else:
    print "NO"
elif len(nums) == 3:
  for i in range(1, 10000):
    if good(sorted(nums + [i])):
      print "YES"
      print i
      exit()
  print "NO"
else:
  if 3*nums[0] < nums[1]:
    print "NO"
  else:
    print "YES"
    print 4*nums[0] - nums[1]
    print 3*nums[0]
