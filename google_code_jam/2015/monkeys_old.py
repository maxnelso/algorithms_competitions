import math
import itertools
import sys

FILENAME = 'B-small-attempt1'

def solve(keyboard, target, current, s, p):
  if len(current) == s:
    total = 0
    for i in range(s - len(target) + 1):
      if current[i:i + len(target)] == target:
        total += 1
    print current, total, p
    return total * p
  out = 0
  for key in keyboard:
    out += solve(keyboard, target, current + key, s, p * 1.0 / len(keyboard))
  return out



f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  k, l, s = map(int, f.readline().split())
  keyboard = f.readline().rstrip()
  target = f.readline().rstrip()
  good = True
  for c in target:
    if c not in keyboard:
      good = False
      break

  if good:
    out = solve(keyboard, target, '', s, 1)
    builder = ''
    while len(builder) != s:
      for c in target:
        builder += c
        if len(builder) == s:
          break
    total = 0
    for i in range(s - len(target) + 1):
      if builder[i:i + len(target)] == target:
        total += 1
    print 'Total', total
    out = total - out
    print 'Case #%d: %f' % (test + 1, out)
  else:
    print 'Case #%d: 0.0' % (test + 1)
