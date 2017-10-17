import math

min_x = 10e10
max_x = -10e10
min_y = 10e10
max_y = -10e10

n = int(raw_input())

for i in range(n):
  x, y = map(int, raw_input().split())
  min_x = min(min_x, x)
  max_x = max(max_x, x)
  min_y = min(min_y, y)
  max_y = max(max_y, y)
largest_diff = max(max_y - min_y, max_x - min_x)
print largest_diff ** 2
