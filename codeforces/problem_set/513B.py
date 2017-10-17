import math
import itertools
import sys

def test(A):
  out = 0
  for i in range(len(A)):
    for j in range(i + 1, len(A) + 1):
      out += min(A[i:j])
  return out

'''
def main():
  n, m = map(int, raw_input().split())
  l = range(1, n + 1)
  good = test(l)
  out = []
  for a in itertools.permutations(l):
    if good == test(a):
      out.append(a)
      print a
  print " ".join([str(x) for x in out[m - 1]])
'''
def main():
  n, m = map(int, raw_input().split())
  candidates = range(1, n + 1)
  m -= 1
  index = 0
  out = ""
  while len(candidates) > 0:
    start = candidates[-1]
    flag = False
    jump = 1
    while index < m:
      if jump == 1 and flag:
        index += 1
        jump = 2
      elif jump == 1:
        flag = True;
        index += 1
      else:
        index += jump
        jump = 2*jump
      start -= 1
    if index > m:
      start += 1
      if jump == 1:
        index -= 1
      else:
        index -= jump / 2
    candidates.remove(start)
    out = str(start) + " " + out
  print out


if __name__ == '__main__':
  main()
