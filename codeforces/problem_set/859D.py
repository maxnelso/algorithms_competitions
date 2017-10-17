import math
import sys
import itertools

matrix = []

def play_tournament(ordering, N):
  pairs = []
  for i in range(2**n):
    pairs.append([i, i + 1])
  out = 0
  for i in range(n):
    new_pairs = []
    pair = []
    for j in range(len(pairs)):
      first = pairs[j][0]
      second = pairs[j][1]
      if ordering.index(first) < ordering.index(second):
        out += matrix[first][second]
        pair.append(first)
      else:
        out += matrix[second][first]
        pair.append(second)
      if len(pair) == 2:
        new_pairs.append(pair)
        pair = []
    pairs = new_pairs
  return out

def main():
  n = map(int, raw_input())
  for i in range(2 ** n):
    row = []
    for j in range(2 ** n):
      a = map(int, raw_input())
      row.append(a)
    matrix.append(row)
  out = 0
  for 


if __name__ == '__main__':
  main()
