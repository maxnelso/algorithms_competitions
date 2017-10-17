import math
import sys

def main():
  n = int(raw_input())
  if n == 1:
    print 1
    print 1
  elif n == 2:
    print 1
    print 1
  elif n == 3:
    print 2
    print "1 3"
  elif n == 4:
    print 4
    print "2 4 1 3"
  else:
    print n
    index = 1
    for i in range(n):
      print index,
      index += 2
      if index > n:
        index = 2

if __name__ == '__main__':
  main()
