import math
import sys

def main():
  a, b = map(int, raw_input().split())
  if b == a:
    print "infinity"
    return
  elif b > a:
    print "0"
    return
  diff = a - b
  print a % diff
  print a % (diff - 1)
  print a % (diff - 2)
  print a % (diff - 3)
  print a % (diff - 4)
  print a % (diff - 5)
  print a % (diff - 6)
  print a % (diff - 7)
  print a % (diff - 8)
  print a % (diff - 9)


if __name__ == '__main__':
  main()
