import math
import sys

def main():
  k = int(raw_input())
  if k == 1:
    print 'YES'
    print 2, 1
    print 1, 2
    return
  num_vertices = k * 2 + 2
  print 'YES'
  for i in range(num_vertices / 2):
    for j in range(num_vertices / 2):
      if i != j:
        if i == 0 and j == 1:
          continue
        print i + 1, j + 1
  for i in range(num_vertices / 2, num_vertices):
    for j in range(num_vertices / 2, num_vertices):
      if i != j:
        if i == num_vertices / 2 and j == num_vertices / 2 + 1:
          continue
        print i + 1, j + 1
  print 1, num_vertices / 2 + 1
  print num_vertices / 2 + 1, 1



if __name__ == '__main__':
  main()
