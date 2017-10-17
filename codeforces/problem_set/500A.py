import math
import sys

def main():
  n, t = map(int, raw_input().split())
  a_s = map(int, raw_input().split())
  index = 1
  while index - 1 < len(a_s):
    if index == t:
      print 'YES'
      return
    index += a_s[index - 1]
  if index == t:
    print 'YES'
    return
  print 'NO'
  return

if __name__ == '__main__':
  main()
