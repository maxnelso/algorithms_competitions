import math
import sys

def is_palindrome(s):
  return s == s[::-1]

def main():
  s = raw_input()
  k = int(raw_input())
  palindromes = []
  if len(s) % k != 0:
    print 'NO'
    return
  else:
    size = len(s) / k
    for i in range(len(s)):
      if i % size == 0:
        if not is_palindrome(s[i:i + size]):
          print 'NO'
          return
  print 'YES'


if __name__ == '__main__':
  main()
