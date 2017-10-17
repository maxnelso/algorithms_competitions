"""
Given a string s, returns a list A, where A[i] is the length
of the longest prefix of s starting at index i in s.
"""
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

