import math
import sys
import copy

def main():
  s = raw_input()
  best = 0
  for i in range(0, len(s), 2):
    for j in range(i + 2, len(s), 2):
      c = s[:i] + '(' + s[i:j+1] + ')' + s[j+1:]
      best = max(best, eval(c))
  print best

if __name__ == '__main__':
  main()
