import math
import sys

def main():
  out = 0
  n = int(raw_input())
  lights = map(int, raw_input().split())
  current_nodes = 2**n
  current_index = len(lights)
  current_index -= current_nodes
  current_lights = lights[current_index:]
  next_lights = []
  for i in range(0, len(current_lights), 2):
    a = current_lights[i]
    b = current_lights[i + 1]
    out += max(a, b) - min(a, b)
    next_lights.append(max(a, b))
  n -= 1
  while n > 0:
    current_lights = lights[current_index - 2**n:current_index]
    current_index = current_index - 2**n
    tmp = []
    for i in range(0, len(current_lights), 2):
      a = current_lights[i] + next_lights[i]
      b = current_lights[i + 1] + next_lights[i + 1]
      out += max(a, b) - min(a, b)
      tmp.append(max(a, b))
    next_lights = tmp
    n -= 1

  print out

if __name__ == '__main__':
  main()
