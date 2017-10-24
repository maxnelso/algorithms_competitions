import math
import sys
import re

def main():
  s = raw_input()
  out = 0
  out += len([m.start() for m in re.finditer('Danil', s)])
  out += len([m.start() for m in re.finditer('Olya', s)])
  out += len([m.start() for m in re.finditer('Slava', s)])
  out += len([m.start() for m in re.finditer('Ann', s)])
  out += len([m.start() for m in re.finditer('Nikita', s)])
  if out == 1:
    print "YES"
  else:
    print "NO"

if __name__ == '__main__':
  main()
