import math
import sys

def main():
  start = ["zero", "one", "two", "three", "four", "five", "six", "seven",
  "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
  "sixteen", "seventeen", "eighteen", "nineteen"]
  prefixes = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy",
  "eighty", "ninety"]
  n = int(raw_input())
  if n <= len(start) - 1:
    print start[n]
  else:
    out = ""
    digit = int(str(n)[0])
    digit -= 2
    prefix = prefixes[digit]
    other = int(str(n)[1])
    out += prefix
    if n % 10 != 0:
      out += "-"
      out += start[other]
    print out


if __name__ == '__main__':
  main()
