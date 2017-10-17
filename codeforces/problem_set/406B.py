import math
import sys

s = 1000000
def main():
  n = int(raw_input())
  X = map(int, raw_input().split())
  X = set(X)
  Y = set()
  bad_pairs = 0
  for k in X:
    symmetric = s + 1 - k
    if symmetric not in X:
      Y.add(symmetric)
    else:
      bad_pairs += 1
  X.update(set(Y))
  bad_pairs /= 2
  if bad_pairs != 0:
    for i in range(1, s + 1):
      if i not in X:
        Y.add(i)
        Y.add(s - i + 1)
        bad_pairs -= 1
        if bad_pairs == 0:
          break
  print len(Y)
  print ' '.join(map(str, Y))



if __name__ == '__main__':
  main()
