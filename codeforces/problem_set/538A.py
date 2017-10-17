import math
import sys

def main():
  string = 'CODEFORCES'
  s = raw_input()
  for i in range(len(s)):
    for j in range(i, len(s)):
      new_s = s[:i] + s[j:]
      if string == new_s:
        print 'YES'
        return
  print 'NO'

if __name__ == '__main__':
  main()
