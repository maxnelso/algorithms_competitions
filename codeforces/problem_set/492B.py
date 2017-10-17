import math
import sys

def main():
  n, l = map(int, raw_input().split())
  lights = map(int, raw_input().split())
  lights.sort()
  maximum = max(lights[0], l - lights[-1])
  for i in range(len(lights) - 1):
    distance = lights[i + 1] - lights[i]
    maximum = max(maximum, distance / 2.0)
  print maximum

if __name__ == '__main__':
  main()
