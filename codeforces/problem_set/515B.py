import math
import sys

def main():
  n, m = map(int, raw_input().split())
  happy_boys = map(int, raw_input().split())
  happy_girls = map(int, raw_input().split())
  happy_boys = happy_boys[1:]
  happy_girls = happy_girls[1:]
  boys = [0] * n
  girls = [0] * m
  for i in happy_boys:
    boys[i] = 1
  for i in happy_girls:
    girls[i] = 1
  for i in range(10000):
    boy_index = i % n
    girl_index = i % m
    if (boys[boy_index] == 0 and girls[girl_index] == 1) or \
       (boys[boy_index] == 1 and girls[girl_index] == 0):
      boys[boy_index] = 1
      girls[girl_index] = 1
  for boy in boys:
    if boy == 0:
      print 'No'
      return
  for girl in girls:
    if girl == 0:
      print 'No'
      return

  print 'Yes'

if __name__ == '__main__':
  main()
