import math
import sys

def med(A):
  index = (len(A) - 1) / 2
  if len(A) % 2 == 0:
    return (A[index] + A[index + 1]) / 2
  return A[index]

def main():
  n, k, p, x, y = map(int, raw_input().split())
  nums = map(int, raw_input().split())
  nums.sort()
  for median in range(y, p):
    copy = nums[:]
    copy.sort()
    out = []
    while len(copy) != n:
      m = med(copy)
      if m < y:
        out.append(median)
        copy.insert((len(copy) - 1) / 2, median)
      else:
        out.append(1)
        copy.insert(0, 1)
    if sum(copy) <= x:
      print ' '.join([str(x) for x in out])
      return
  print -1

if __name__ == '__main__':
  main()
