import math

n, m = map(int, raw_input().split())

for num_moves in xrange(m, n + 1, m):
  for num_ones in xrange(0, num_moves + 1):
    num_twos = num_moves - num_ones
    if num_ones + 2*num_twos == n:
      print num_moves
      exit()
    else:
      continue
print -1
