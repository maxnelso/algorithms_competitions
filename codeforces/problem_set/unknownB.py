import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  start = -1
  end = -1
  for i in range(len(nums) - 1):
    if nums[i] > nums[i + 1]:
      start = i
      for j in range(i + 1, len(nums)):
        if nums[j] > nums[j - 1]:
          end = j - 1
          break
      if end == -1:
        end = len(nums) - 1
      break
  if start == -1 and end == -1:
    start = 0
    end = 0
  middle = nums[start:end + 1]
  middle.reverse()
  fixed = nums[:start] + middle + nums[end + 1:]
  if sorted(fixed) == fixed:
    print "yes"
    print start + 1, end + 1
  else:
    print "no"

if __name__ == '__main__':
  main()
