import math
import sys

def main():
  a = sum(map(int, raw_input().split()))
  b = sum(map(int, raw_input().split()))
  n = int(raw_input())
  a_shelves = a / 5
  if a % 5 != 0:
    a_shelves += 1
  b_shelves = b / 10
  if b % 10 != 0:
    b_shelves += 1
  if a_shelves + b_shelves <= n:
    print 'YES'
  else:
    print 'NO'

if __name__ == '__main__':
  main()
