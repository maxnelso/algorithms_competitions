import math
import sys

def main():
  n, x, y = map(int, raw_input().split())
  hits = []
  for i in range(n):
    hits.append(int(raw_input()))
  between_second = [''] * (x + y - 2)
  a = 1
  b = 1
  for i in range(len(between_second)):
    if a == x and b == y:
      break
    elif a == x:
      between_second[i] = 'Vova'
      b += 1
    elif b == y:
      between_second[i] = 'Vanya'
      a += 1
    elif float(a) / x < float(b) / y:
      between_second[i] = 'Vanya'
      a += 1
    elif float(a) / x > float(b) / y:
      between_second[i] = 'Vova'
      b += 1
    else:
      between_second[i] = 'Both'
      between_second.pop()
      a += 1
      b += 1
  between_second.append('Both')
  for i in range(len(hits)):
    hits[i] = hits[i] % len(between_second)
    index = 0
    if hits[i] == 0:
      print 'Both'
      continue
    while hits[i] > 0:
      if between_second[index] == 'Both':
        hits[i] -= 2
      else:
        hits[i] -= 1
      if hits[i] <= 0:
        break
      index = (index + 1) % len(between_second)
    print between_second[index]


if __name__ == '__main__':
  main()
