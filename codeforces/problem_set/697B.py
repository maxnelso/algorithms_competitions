import math
import sys

def main():
  s = raw_input()
  num, exp = s.split("e")
  exp = int(exp)
  dec_index = num.find(".")
  replaced = num.replace(".", "")
  if exp == 0:
    if int(num[dec_index + 1:]) == 0:
      print int(num[:dec_index])
      return

    print num
    return
  if len(num) - dec_index <= exp + 1:
    zeroes = exp - (len(num) - dec_index - 1)
    print (replaced + ("0" * zeroes)).lstrip("0")
  else:
    dec_index += int(exp)
    print replaced[:dec_index] + "." + replaced[dec_index:]


if __name__ == '__main__':
  main()
