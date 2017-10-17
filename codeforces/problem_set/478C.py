import math
import itertools

r, g, b = map(int, raw_input().split())

def solve(r_, g_, b_, p):
  out = 0
  for t in p:
    if t == "mixed":
      min_ = min(min(r_, g_), b_)
      out += min_
      r_ -= min_
      g_ -= min_
      b_ -= min_
    if t == "rrg":
      min_ = min(g_, r_ / 2)
      out += min_
      r_ -= min_ * 2
      g_ -= min_
    if t == "rrb":
      min_ = min(b_, r_ / 2)
      out += min_
      r_ -= min_ * 2
      b_ -= min_
    if t == "bbr":
      min_ = min(r_, b_ / 2)
      out += min_
      b_ -= min_ * 2
      r_ -= min_
    if t == "bbg":
      min_ = min(g_, b_ / 2)
      out += min_
      b_ -= min_ * 2
      g_ -= min_
    if t == "ggr":
      min_ = min(r_, g_ / 2)
      out += min_
      g_ -= min_ * 2
      r_ -= min_
    if t == "ggb":
      min_ = min(b_, g_ / 2)
      out += min_
      g_ -= min_ * 2
      b_ -= min_
  return out



ordering = ["mixed", "rrg", "rrb", "bbr", "bbg", "ggr", "ggb"]

best = 0
for p in itertools.permutations(ordering):
  best = max(best, solve(r, g, b, p))

print best
