import math
import copy
import string

n, p = map(int, raw_input().split())
p -= 1
s = raw_input()
char_diffs = []
char_sum = 0
baddies = 0
for i in range(n / 2):
  bigger = max(string.lowercase.index(s[i]), string.lowercase.index(s[n - i - 1]))
  smaller = min(string.lowercase.index(s[i]), string.lowercase.index(s[n - i - 1]))
  left = bigger - smaller
  right = 26 - bigger + smaller
  char_diffs.append(min(left, right))
  char_sum += min(left, right)
  if min(left, right) != 0:
    baddies += 1

if n % 2 == 1:
  char_diffs.append(0)
  for i in range(n /2 ):
    char_diffs.append(char_diffs[n / 2 - i - 1])
else:
  for i in range(n /2 ):
    char_diffs.append(char_diffs[n / 2 - i - 1])
best = 10000000000000000
if baddies == 0:
  best = 0
for i in range(baddies + 1):
  num_rights = 0
  copy_diffs = copy.copy(char_diffs)
  copy_sum = copy.copy(char_sum)
  copy_p = copy.copy(p)
  count = 0
  while True:
    if copy_diffs[copy_p] != 0:
      count += copy_diffs[copy_p]
      copy_sum -= copy_diffs[copy_p]
      copy_diffs[copy_p] = 0
      copy_diffs[n - copy_p - 1] = 0
      if num_rights < i:
        num_rights += 1
    if copy_sum == 0:
      break
    count += 1
    if num_rights < i:
      copy_p = (copy_p + 1) % n
    else:
      copy_p = (copy_p - 1) % n
  best = min(count, best)

print best
