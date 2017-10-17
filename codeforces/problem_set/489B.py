import math
import sys

def main():
  n = int(raw_input())
  boys = map(int, raw_input().split())
  m = int(raw_input())
  girls = map(int, raw_input().split())
  boys.sort()
  girls.sort()
  boy_index = 0
  girl_index = 0
  out = 0
  while girl_index < m and boy_index < n:
    if abs(boys[boy_index] - girls[girl_index]) <= 1:
      out += 1
      boy_index += 1
      girl_index += 1
    elif boys[boy_index] < girls[girl_index]:
      boy_index += 1
    else:
      girl_index += 1
  print out

if __name__ == '__main__':
  main()
