import math
import sys

def main():
  n = int(raw_input())
  height = 0
  cubes = 1
  while n >= cubes:
    n -= cubes
    height += 1
    cubes += height + 1
  print height

if __name__ == '__main__':
  main()
