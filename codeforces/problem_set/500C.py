import math
import sys

def main():
  n, m = map(int, raw_input().split())
  weights = map(int, raw_input().split())
  order = map(int, raw_input().split())
  stack = []
  seen = {}
  for i in range(m):
    if order[i] in seen:
      continue
    seen[order[i]] = True
    stack.append(order[i])
  out = 0
  for i in range(m):
    index = stack.index(order[i])
    for j in range(index):
      out += weights[stack[j] - 1]
    stack.remove(order[i])
    stack.insert(0, order[i])
  print out

if __name__ == '__main__':
  main()
