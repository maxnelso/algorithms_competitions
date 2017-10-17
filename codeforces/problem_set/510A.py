import math
import sys

def main():
  n, m = map(int, raw_input().split())
  flag = True
  odd = True
  for i in range(n):
    if flag:
      print m * "#"
    else:
      if odd:
        print (m - 1) * "." + "#"
      else:
        print "#" + (m - 1) * "."
      odd = not odd
    flag = not flag

if __name__ == '__main__':
  main()
