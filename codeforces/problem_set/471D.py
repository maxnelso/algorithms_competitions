import math

n, w = map(int, raw_input().split())
heights = map(int, raw_input().split())
elephant = map(int, raw_input().split())

def z_function(s):
  length = len(s)
  z = [0] * length
  l = 0
  r = 0
  for i in range(1, length):
    if (i <= r):
      z[i] = min (r-i+1, z[i-l])
    while (i+z[i] < length and s[z[i]] == s[i+z[i]]):
      z[i] += 1
    if (i+z[i]-1 > r):
      l = i
      r = i+z[i]-1
  return z

def find_number_of_occurrences(diffs, pattern):
  if len(pattern) == 0:
    return len(diffs) + 1
  s = pattern + diffs

  z = z_function(s)
  result = 0
  for i in range(len(pattern), len(z)):
    if z[i] >= len(pattern):
      result += 1
  return result

diffs = [elephant[i + 1] - elephant[i] for i in xrange(len(elephant) - 1)]
diffs_heights = [heights[i + 1] - heights[i] for i in xrange(len(heights) - 1)]


print find_number_of_occurrences(diffs_heights, diffs)
