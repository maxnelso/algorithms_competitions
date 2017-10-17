import math
import sys

def main():
  n = int(raw_input())
  first = []
  second = []
  first_sum = 0
  second_sum = 0
  for i in range(n):
    a = int(raw_input())
    if i == n - 1:
      if a < 0:
        last = 'second'
      else:
        last = 'first'
    if a < 0:
      a = abs(a)
      second.append(a)
      second_sum += a
    else:
      first.append(a)
      first_sum += a
  if first_sum > second_sum:
    print 'first'
  elif second_sum > first_sum:
    print 'second'
  else:
    for i in range(min(len(first), second)):
      if first[i] > second[i]:
        print 'first'
        return
      elif second[i] > first[i]:
        print 'second'
        return
    if len(first) > len(second):
      print 'first'
    elif len(second) > len(first):
      print 'second'
    else:
      print last


if __name__ == '__main__':
  main()
