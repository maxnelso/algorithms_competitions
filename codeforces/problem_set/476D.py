import math

n, k = map(int, raw_input().split())
sets = []
for a in range(0, n):
  sets.append([6 * a + 1, 6 * a + 2, 6 * a + 3, 6 * a + 5])
sets = [[str(x * k) for x in s] for s in sets]
print (6 *n - 1) * k
for s in sets:
  print ' '.join(s)
