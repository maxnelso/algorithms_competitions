import math
import sys
import Queue

seen = {}

def main():
  n, m = map(int, raw_input().split())
  queue = Queue.Queue()
  queue.put((n, 0))
  seen[n] = True
  while not queue.empty():
    element = queue.get()
    seen[element[0]] = True
    if element[0] == m:
      print element[1]
      return
    if element[0] < m:
      if element[0] * 2 not in seen:
        queue.put((element[0] * 2, element[1] + 1))
      if element[0] - 1 not in seen and element[0] - 1 > 0:
        queue.put((element[0] - 1, element[1] + 1))
    else:
      if element[0] - 1 not in seen and element[0] - 1 > 0:
        queue.put((element[0] - 1, element[1] + 1))

if __name__ == '__main__':
  main()
