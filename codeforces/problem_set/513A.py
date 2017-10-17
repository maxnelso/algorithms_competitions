import math
import sys

def main():
  n1, n2, k1, k2 = map(int, raw_input().split())
  if n2 >= n1:
    print "Second"
  else:
    print "First"

if __name__ == '__main__':
  main()
