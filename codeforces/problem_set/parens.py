import math
import sys

def main():
  s = raw_input()
  balance = 0
  best = 0
  index = 0
  for i in range(len(s)):
    c = s[i]
    if c == '(':
      balance += 1
    else:
      balance -= 1
    if balance < best:
      best = balance
      index = i
  print index
  n = len(s)
  s = s + s
  s = s[index:index + n]
  print s

if __name__ == '__main__':
  main()
