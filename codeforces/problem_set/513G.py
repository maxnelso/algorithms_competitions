import math
import sys

memo = {}

def num_inversions(A):
  out = 0
  for i in range(len(A)):
    for j in range(i + 1, len(A)):
      if A[i] > A[j]:
        out += 1
  return out

def solve(permutation, k, p):
  if k == 0:
    return num_inversions(permutation) * p
  if (tuple(permutation), k) in memo:
    return memo[(tuple(permutation), k)]
  if len(permutation) == 1:
    uniform = 1
  else:
    uniform = (len(permutation) * (len(permutation) + 1)) / 2
  out = 0
  for i in range(0, len(permutation)):
    for j in range(i, len(permutation)):
      new_permutation = permutation[:i] + permutation[i:j + 1][::-1] + permutation[j + 1:]
      out += solve(new_permutation, k - 1, p * 1.0 / uniform)
  memo[(tuple(permutation), k)] = out
  return out

def main():
  n, k = map(int, raw_input().split())
  permutation = map(int, raw_input().split())
  print solve(permutation, k, 1)

if __name__ == '__main__':
  main()
