import math
import sys

def main():
  n, q = map(int, raw_input().split())
  m = {}
  for i in range(n):
    s = raw_input()
    for i in range(len(s)):
      c = s[i]
      if c == 'a':
        new_s = s[:i] + 'b' + s[i+1:]
        m[new_s] = True
        new_s = s[:i] + 'c' + s[i+1:]
        m[new_s] = True
      if c == 'b':
        new_s = s[:i] + 'a' + s[i+1:]
        m[new_s] = True
        new_s = s[:i] + 'c' + s[i+1:]
        m[new_s] = True
      if c == 'c':
        new_s = s[:i] + 'a' + s[i+1:]
        m[new_s] = True
        new_s = s[:i] + 'b' + s[i+1:]
        m[new_s] = True
  for i in range(q):
    s = raw_input()
    if s in m:
      print 'YES'
    else:
      print 'NO'

if __name__ == '__main__':
  main()
