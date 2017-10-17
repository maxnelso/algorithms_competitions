import math
import sys

memo = {}
used = {}
gems = [0] * 30001
D = -1

def solve(n, d):
  index = d - (D - 250)
  if n >= 30001:
    return count
  print (n, index)
  if (n, index) in used:
    return memo[(n, index)]
  used[(n, index)] = True
  result = 0
  if d == 1:
    result = gems[n] + max(result, solve(n + d, d), solve(n + d + 1, d + 1))
  else:
    result = gems[n] + max(result, solve(n + d, d), solve(n + d + 1, d + 1), solve(n + d - 1, d - 1))
  memo[(n, index)] = result
  return best


def main():
  n, D = map(int, raw_input().split())
  spots = map(int, raw_input().split())
  for spot in spots:
    gems[spot] += 1
  print solve(D, D)

if __name__ == '__main__':
  main()
