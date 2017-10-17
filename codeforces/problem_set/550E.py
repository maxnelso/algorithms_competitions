import math
import sys

def main():
  n = int(raw_input())
  s = map(int, raw_input().split())
  if s[n - 1] == 1:
    print 'NO'
    return
  if n == 1:
    print 'YES\n0'
    return
  if s[n - 2] == 1:
    print 'YES'
    for i in range(n - 1):
      sys.stdout.write(str(s[i]))
      sys.stdout.write('->')
    print 0
    return
  for i in range(n - 3, -1, -1):
    if s[i] == 0:
      print 'YES'
      for j in range(i):
        sys.stdout.write(str(s[j]))
        sys.stdout.write('->')
      sys.stdout.write('(0->(')
      for j in range(i + 1, n - 2):
        sys.stdout.write(str(s[j]))
        sys.stdout.write('->')
      sys.stdout.write('0))->0')
      return

  print 'NO'

if __name__ == '__main__':
  main()
