import math
import sys

def main():
  n = int(raw_input())
  edges = {}
  counts = {}
  for i in range(n):
    a, b = map(int, raw_input().split())
    edges[a] = b
    if a in counts:
      counts[a] += 1
    else:
      counts[a] = 1
    if b in counts:
      counts[b] += 1
    else:
      counts[b] = 1
  potentials = []
  for key in counts:
    if counts[key] != 2:
      potentials.append(key)
  if potentials[0] in edges:
    start, end = potentials
  else:
    end, start = potentials
  if n == 2:
    print start, end
    return
  node = edges[0]
  prev = start
  order = [start, node]
  while edges[node] != 0:
    node, prev = edges[prev], node
    order.append(node)
  order.append(end)
  print " ".join([str(x) for x in order])

if __name__ == '__main__':
  main()
