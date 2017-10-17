import math

def get_sum(a):
  return a * (a - 1) / 2

n, m = map(int, raw_input().split())
per_group = n / m
leftovers = n % m
min_ = (m - leftovers) * get_sum(per_group) + leftovers * get_sum(per_group + 1)
max_ = get_sum(max(n - (m - 1), 1))
print min_, max_
