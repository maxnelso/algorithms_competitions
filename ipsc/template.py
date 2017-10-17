import math
import itertools
import sys

FILENAME = 'file'

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for test in range(tests):
  print 'Case #%d: ' % (test,)
