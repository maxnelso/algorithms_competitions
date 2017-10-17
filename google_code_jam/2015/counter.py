import math
import itertools

def dist(a, n):
  return abs(n - a)

f = open("A-small-attempt0.in", "r")
tests = int(f.readline())
out = open("A-small.out", "w")
#for i in range(tests):
#n = int(f.readline())
for i in range(1, 1000):
  a = 0
  current = 1
  n = i
  while current != n:
    flipped = int(str(current)[::-1])
    next_flipped = int(str(current + 1)[::-1])
    if current + 1 == n:
      current += 1
    elif flipped == n:
      current = flipped
    elif flipped > current + 1 and flipped <= n:
      if next_flipped <= n and next_flipped > flipped + 1:
        current += 1
      else:
        current = flipped
    else:
      current += 1
    out.write("{0}\n".format(current))
    a += 1

  out.write("Case #{1}: {0}\n".format(a + 1, i))
