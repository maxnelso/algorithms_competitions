import math
import sys

def main():
  s = raw_input()
  t = raw_input()
  for i in range(len(s)):
    if s[i] != t[i]:
      s = s[:i] + chr(ord(s[i]) + 1) + ('a' * (len(s) - i - 1))
      break
  if s != t:
    print s
  else:
    print 'No such string'

if __name__ == '__main__':
  main()
