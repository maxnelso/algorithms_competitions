import math
import sys
import itertools

def main():
  w, m = map(int, raw_input().split())
  sums = []
  for i in range(10):
    sums.append(w ** i)
    sums.append(-(w ** i))
  for i in range(1, len(sums) + 1):
    for combo in itertools.combinations(sums, i):
      if sum(combo) == m:
        print 'YES'
        return
  print 'NO'


if __name__ == '__main__':
  main()
