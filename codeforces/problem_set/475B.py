import math
import Queue

n, m = map(int, raw_input().split())
rows = list(raw_input())
cols = list(raw_input())

def get_adjacent(j):
  adj = []
  if rows[j[0]] == '>':
    for i in range(j[1] + 1, len(cols)):
      a = (j[0], i)
      if a not in seen:
        seen[a] = True
        adj.append(a)
  else:
    for i in range(j[1] - 1, -1, -1):
      a = (j[0], i)
      if a not in seen:
        seen[a] = True
        adj.append(a)
  if cols[j[1]] == 'v':
    for i in range(j[0] + 1, len(rows)):
      a = (i, j[1])
      if a not in seen:
        seen[a] = True
        adj.append(a)
  else:
    for i in range(j[0] - 1, -1, -1):
      a = (i, j[1])
      if a not in seen:
        seen[a] = True
        adj.append(a)
  return adj

for i in range(m):
  for j in range(n):
    junction = (j, i)
    seen = {}
    seen[junction] = True
    count = 0
    queue = Queue.Queue()
    queue.put(junction)
    while not queue.empty():
      count += 1
      adj = get_adjacent(queue.get())
      for a in adj:
        queue.put(a)
    if count != m * n:
      print "NO"
      exit()
print "YES"
