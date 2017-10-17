import math

n, m, a, b = map(int, raw_input().split())

best = 1000000000
for i in range(0, n/m + 2):
  rides_left = n - i*m
  cost = max(rides_left, 0) * a + i*b
  best = min(cost, best)
print best
