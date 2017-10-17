import math
import itertools
import sys

FILENAME = 'b2'

f = open(FILENAME + '.in', 'r')
sys.stdout = open(FILENAME + '.out', 'w')
m = int(f.readline().rstrip())
adjectives = {}
for i in range(m):
  s, a = f.readline().rstrip().split()
  a = int(a)
  adjectives[s] = a
compounds = {}
m = int(f.readline().rstrip())
for i in range(m):
  s, a = f.readline().rstrip().split()
  a = int(a)
  compounds[s] = a
nouns = {}
m = int(f.readline().rstrip())
for i in range(m):
  s, a = f.readline().rstrip().split()
  a = int(a)
  nouns[s] = a
sums = {}
for a in adjectives:
  for c in compounds:
    total = adjectives[a] + compounds[c]
    if total in sums:
      sums[total].append((a,c))
    else:
      sums[total] = [(a,c)]
m = int(f.readline().rstrip())
seen = {}
print sums

'''
for i in range(m):
  a, b, c = f.readline().rstrip().split()
  total = adjectives[a] + compounds[b] + nouns[c]
  for n in nouns:
    key = total + 1 - nouns[n]
    if key in sums:
      found = False
      for a1, c1 in sums[key]:
        if (a1, c1, n) in seen:
          continue
        print a1, c1, n
        seen[(a1, c1, n)] = True
        found = True
        break
      if found:
        break
'''
