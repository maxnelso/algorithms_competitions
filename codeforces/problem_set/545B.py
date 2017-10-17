import math
import sys

def dist(a, b):
  out = 0
  for i in range(len(b)):
    if a[i] != b[i]:
      out += 1
  return out

def main():
  s = raw_input()
  t = raw_input()
  out = ''
  if dist(s, t) % 2 != 0:
    print 'impossible'
    return
  flag = True
  for i in range(len(s)):
    if s[i] == t[i]:
      out += s[i]
    else:
      if flag:
        out += s[i]
      else:
        out += t[i]
      flag = not flag
  print out

if __name__ == '__main__':
  main()
