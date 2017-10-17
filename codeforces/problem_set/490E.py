import math
import sys

nums = []

def best(s):
  out = ''
  if s[0] == '?':
    out += '1'
  else:
    out += s[0]
  for i in range(1, len(s)):
    if s[i] == '?':
      out += '0'
    else:
      out += s[i]
  return out

def main():
  n = int(raw_input())
  for i in range(n):
    nums.append(list(raw_input()))
  nums[0] = best(nums[0])
  for i in range(1, n):
    if len(nums[i - 1]) > len(nums[i]):
      print 'NO'
      return
    if len(nums[i - 1]) < len(nums[i]):
      nums[i] = best(nums[i])
      continue
    res = 'BAD'
    for j in range(len(nums[i])):
      if nums[i][j] == '?':
        if nums[i - 1][j] != '9':
          nums[i][j] = str(int(nums[i - 1][j]) + 1)
          res = best(nums[i])
        nums[i][j] = nums[i - 1][j]
      else:
        if nums[i - 1][j] < nums[i][j]:
          res = best(nums[i])
          break
        if nums[i - 1][j] > nums[i][j]:
          break
    if res == 'BAD':
      print res
      return
    nums[i] = res
  print 'YES'
  for i in range(n):
    print nums[i]


if __name__ == '__main__':
  main()
