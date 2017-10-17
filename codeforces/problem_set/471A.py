import math

lengths = map(int, raw_input().split())

counts = {}
for l in lengths:
  if l in counts:
    counts[l] = counts[l] + 1
  else:
    counts[l] = 1

legs = -1
for c in counts:
  if counts[c] >= 4:
    legs = c
    counts[c] = counts[c] - 4

if legs == -1:
  print "Alien"
else:
  for i in range(4):
    lengths.remove(legs)

  if lengths[0] == lengths[1]:
    print "Elephant"
  else:
    print "Bear"
