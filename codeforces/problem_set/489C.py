import math
import sys

def solve_max(m, s, start):
  if m == 1:
    return str(s)
  for i in range(min(9, s), start - 1, -1):
    if s - i <= (m - 1) * 9:
      return str(i) + solve_max(m - 1, s - i, 0)
  return ''

def solve_min(m, s, start):
  if m == 1:
    return str(s)
  for i in range(start, min(9, s) + 1):
    if s - i <= (m - 1) * 9:
      return str(i) + solve_min(m - 1, s - i, 0)
  return ''

def main():
  m, s = map(int, raw_input().split())
  if m == 1 and s == 0:
    print '0 0'
    return
  if s == 0:
    print '-1 -1'
    return
  if s > 9 * m:
    print '-1 -1'
    return
  print '{0} {1}'.format(solve_min(m, s, 1), solve_max(m, s, 1))

if __name__ == '__main__':
  main()
