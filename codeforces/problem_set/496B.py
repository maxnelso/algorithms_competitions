import math
import sys

def next_string(s):
  tmp = s
  tmp.pop()
  tmp.insert(0, s[-1])
  return tmp

def press_button(s):
  out = ""
  for i in range(len(s)):
    out += str(((int(s[i]) + 1) % 10))
  return out

def main():
  n = int(raw_input())
  digits = raw_input()
  out = -1
  for i in range(n + 1):
    digits = next_string(digits)
    s = digits
    for j in range(10):
      if out == -1 or int(s) < out:
        out = int(s)
      s = press_button(s)
  print str(out).zfill(n)


if __name__ == '__main__':
  main()
