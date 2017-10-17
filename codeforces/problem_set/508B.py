import math
import sys

def main():
  s = raw_input()
  best = 100000
  best_i = 0
  for i in range(len(s) - 1):
    if int(s[i]) % 2 == 0:
      if int(s[i]) <= best:
        best = int(s[i])
        best_i = i
  if best == 100000:
    print -1
  else:
    i = best_i
    print s[:i] + s[-1] + s[i + 1:len(s) - 1] + s[i]

if __name__ == '__main__':
  main()
