import math
import sys

def main():
  n, m = map(int, raw_input().split())
  if min(n, m) % 2 == 0:
    print 'Malvika'
  else:
    print 'Akshat'

if __name__ == '__main__':
  main()
