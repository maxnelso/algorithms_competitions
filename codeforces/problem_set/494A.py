import math
import sys

def check(s):
  count = 0
  for i in range(len(s)):
    if s[i] == '(':
      count += 1
    else:
      count -= 1
    if count < 0:
      return False
  return True

def main():
  s = list(raw_input())
  count = 0
  last = 0
  num = 0
  for i in range(len(s)):
    if s[i] == '(':
      count += 1
    elif s[i] == '#':
      s[i] = ')'
      last = i
      count -= 1
      num += 1
    else:
      count -= 1
  if count < 0:
    print -1
    return
  t = s[:last] + ([')'] * (count + 1)) + s[last+1:]
  if not check(t):
    print -1
    return
  for i in range(1, num):
    print 1
  print count + 1


if __name__ == '__main__':
  main()
