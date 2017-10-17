import math
import sys

def main():
  n = int(raw_input())
  s = raw_input()
  keys = {}
  out = 0
  for i in range(2*n - 2):
    if i % 2 == 0:
      c = s[i]
      if c in keys:
        keys[c] += 1
      else:
        keys[c] = 1
    else:
      c = s[i].lower()
      if c not in keys:
        out += 1
      else:
        keys[c] -= 1
        if keys[c] == 0:
          del keys[c]
  print out

if __name__ == '__main__':
  main()
