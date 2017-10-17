import math
import sys

def main():
  n = int(raw_input())
  s = raw_input()
  for i in range(1, 100): # jump length
    for j in range(len(s)): # start index
      good = True
      for k in range(5): # jumps
        if j + k*i >= n or s[j + k*i] == '.':
          good = False
          break
      if good:
        print 'yes'
        return
  print 'no'


if __name__ == '__main__':
  main()
