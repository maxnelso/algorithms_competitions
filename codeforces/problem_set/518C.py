import math
import sys

def main():
  n, m, k = map(int, raw_input().split())
  order = map(int, raw_input().split())
  todo = map(int, raw_input().split())
  index = {}
  for i in range(len(order)):
    index[order[i]] = i
  out = 0
  for x in todo:
    flips = index[x] / k
    out += flips + 1
    swap_index = index[x] - 1
    if swap_index >= 0:
      swap_ele = order[swap_index]
      order[index[x]] = swap_ele
      order[index[x] - 1] = x
      index[swap_ele] = index[x]
      index[x] = index[x] - 1
  print out


if __name__ == '__main__':
  main()
