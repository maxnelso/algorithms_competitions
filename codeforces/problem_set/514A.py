import math
import sys

def main():
  n = raw_input()
  out = ""
  all_nines = True
  for c in n:
    if c != '9':
      all_nines = False
      break
  if all_nines:
    print '9'
    return
  seen_other = False
  for c in n:
    if c != '9':
      seen_other = True
    if c == '9':
      if not seen_other:
        out += '9'
      else:
        out += '0'
      continue
    if int(c) <= 4:
      out += c
    else:
      out += str(9 - int(c))
  print str(int(out))

if __name__ == '__main__':
  main()
