import itertools


for g in itertools.permutations(range(1, 5), 4):
  bad = False
  for i in range(len(g) - 1):
    if g[i] == g[i+1] - 1 or g[i+1] == g[i] - 1:
      bad = True
  if not bad:
    print g
