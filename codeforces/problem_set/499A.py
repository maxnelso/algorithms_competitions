import math
import sys

def hello(hello):
  print 'hio'

def main():
  n, x = map(int, raw_input().split())
  current_time = 1
  watched = 0
  for i in range(n):
    l, r = map(int, raw_input().split())
    while l >= current_time + x:
      current_time += x
    watched += r - current_time + 1
    current_time = r + 1
  print watched

if __name__ == '__main__':
  main()
