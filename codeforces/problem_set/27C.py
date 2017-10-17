import math
import sys

def main():
  n = int(raw_input())
  nums = map(int, raw_input().split())
  out = []
  min_left = [nums[0]]
  max_left = [nums[0]]
  min_right = [nums[-1]]
  max_right = [nums[-1]]
  for i in range(1, len(nums)):
    if nums[i] < min_left[i - 1]:
      min_left.append(nums[i])
    else:
      min_left.append(min_left[i - 1])
    if nums[i] > max_left[i - 1]:
      max_left.append(nums[i])
    else:
      max_left.append(max_left[i - 1])
  for i in range(len(nums) - 2, -1, -1):
    index = len(nums) - i - 2
    if nums[i] < min_right[index]:
      min_right.append(nums[i])
    else:
      min_right.append(min_right[index])
    if nums[i] > max_right[index]:
      max_right.append(nums[i])
    else:
      max_right.append(max_right[index])
  for i in range(1, len(nums) - 1):
    if min_left[i - 1] < nums[i] and min_right[i - 1] < nums[i]:
      print 3
      found_left = False
      found_right = False
      for j in range(len(nums)):
        if nums[j] == min_left[i - 1] and j < i and not found_left:
          out.append(j + 1)
          found_left = True
        if j == i:
          out.append(j + 1)
        if nums[j] == min_right[i - 1] and j > i and not found_right:
          out.append(j + 1)
          found_right = True
          print ' '.join([str(x) for x in out])
          return
    if max_left[i - 1] > nums[i] and max_right[i - 1] > nums[i]:
      print 3
      found_left = False
      found_right = False
      for j in range(len(nums)):
        if nums[j] == max_left[i - 1] and j < i and not found_left:
          out.append(j + 1)
          found_left = True
        if j == i:
          out.append(j + 1)
        if nums[j] == max_right[i - 1] and j > i and not found_right:
          out.append(j + 1)
          found_right = True
          print ' '.join([str(x) for x in out])
          return
  print 0

if __name__ == '__main__':
  main()
