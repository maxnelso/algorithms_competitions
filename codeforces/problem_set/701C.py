import math
import sys

def main():
  n = int(input())
  s = str(raw_input())
  right_most = {}
  for i in range(len(s)):
    right_most[s[i]] = i

  left_most = {}
  for i in range(len(s) - 1, -1, -1):
    left_most[s[i]] = i

  print right_most
  print left_most

  start_index = 1000000
  start_letter = ""
  for key in right_most:
    if right_most[key] < start_index:
      start_letter = key
      start_index = right_most[key]
  print start_index
  end_index = 0
  for key in left_most:
    if key == start_letter:
      continue
    end_index = max(end_index, left_most[key])
  print end_index - start_index



if __name__ == '__main__':
  main()
