import math
import sys

def subs_sum(s, sum):
  subs = [[False for x in range(sum + 1)] for x in range(len(s) + 1)]
  for i in range(len(s) + 1):
    subs[0][i] = True

  for i in range(1, sum + 1):
    subs[i][0] = False

  for i in range(1, sum + 1):
    for j in range(1, len(sum) + 1):
      subs[i][j] = subs[i][j - 1]
      if i >= s[j-1]:
        subs[i][j] = subs[i][j] or subs[i - s[j-1]][j-1]
  return subs[sum][n]

def main():
  w, m = map(int, raw_input().split())
  sums = []
  for i in range(0, 101):
    sums.append(w ** i)
    sums.append(-(w ** i))
  sums.sort()
  if subs_sum(sums, m):
    print 'YES'
  else:
    print 'NO'


if __name__ == '__main__':
  main()
