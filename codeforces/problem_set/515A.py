import math
import sys

def main():
  a, b, s = map(int, raw_input().split())
  a = abs(a)
  b = abs(b)
  if a + b > s:
    print 'No'
  elif (a + b) % 2 != s % 2:
    print 'No'
  else:
    print 'Yes'

if __name__ == '__main__':
  main()
