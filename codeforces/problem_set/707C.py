import math
import sys

def main():
  squares = set()
  for i in range(1, 10**5 + 1):
    squares.add(i**2)
    if (i == 10**5):
      print i**2
  n = int(raw_input())
  n_squared = n**2
  for square in squares:
    if n_squared - square in squares:
      print int(math.sqrt(square)), int(math.sqrt(n_squared - square))
      return
    if n_squared + square in squares:
      print int(math.sqrt(square)), int(math.sqrt(n_squared + square))
      return
  print -1

if __name__ == '__main__':
  main()
