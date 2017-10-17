import math
import fractions

l, r = map(int, raw_input().split())
pairs = []
i = l
while i <= r:
  j = i + 1
  while j <= r:
    if fractions.gcd(i, j) == 1:
      pairs.append((i, j))
      pairs.append((j, i))
    j += 1
  i += 1
pairs.sort()
for i in range(len(pairs)):
  for j in range(i + 1, len(pairs)):
    s = set([pairs[i][0], pairs[i][1], pairs[j][0], pairs[j][1]])
    if len(s) == 3:
      x = list(s)
      x.sort()
      if fractions.gcd(x[0], x[1]) == 1 and fractions.gcd(x[1], x[2]) == 1 and fractions.gcd(x[0], x[2]) != 1:
        out = [str(x[0]), str(x[1]), str(x[2])]
        print " ".join(out)
        exit()
print -1
