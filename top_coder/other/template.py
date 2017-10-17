import itertools
import math

class DifferentStrings:

  def diff(self, s1, s2, index):
    out = 0
    if index + len(s1) > len(s2):
      return 100000
    for i in range(len(s1)):
      if s2[i + index] != s1[i]:
        out += 1
    return out

  def minimize(self, s1, s2):
    if len(s1) > len(s2):
      s1, s2 = s2, s1
    if len(s1) == len(s2):
      return self.diff(s1, s2, 0)
    best = 100000
    for i in range(len(s2)):
      best = min(best, self.diff(s1, s2, i))
    return best

test = DifferentStrings()
print test.minimize("koder", "topcoder")
