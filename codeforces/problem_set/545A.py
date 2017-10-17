import math
import sys

def main():
  n = int(raw_input())
  out = []
  for i in range(n):
    nums = map(int, raw_input().split())
    good = True
    for num in nums:
      if num == 1 or num == 3:
        good = False
        break
    if good:
      out.append(str(i + 1))
  print len(out)
  if len(out) > 0:
    print ' '.join(out)

if __name__ == '__main__':
  main()
