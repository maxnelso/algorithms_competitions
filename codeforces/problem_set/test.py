import random
import itertools

x = range(1, 70)

def random_combination(iterable, r):
  "Random selection from itertools.combinations(iterable, r)"
  pool = tuple(iterable)
  n = len(pool)
  indices = sorted(random.sample(xrange(n), r))
  return tuple(pool[i] for i in indices)

trials = 0
total = 0
size = 2
while True:
  trials += 1
  total +=  min(random_combination(x, size))
  print float(total) / trials
