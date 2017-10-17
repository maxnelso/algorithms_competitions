import math
import sys

def main():
  n = int(raw_input())
  crushes = map(int, raw_input().split())
  cycles = {}

  for i in range(1, n + 1):
    cycle = []
    crush = crushes[i - 1]
    while crush != i and crush not in cycle:
      cycle.append(crush)
      crush = crushes[crush - 1]
    cycles[i] = cycle
  print cycles

if __name__ == '__main__':
  main()
