import math
import sys

def main():
  n = int(raw_input())
  heights = map(int, raw_input().split())
  out = 0
  for i in range(len(heights)):
    tmp = 1
    # Left
    left_index = i - 1
    last = heights[i]
    while left_index >= 0:
      if heights[left_index] <= last:
        tmp += 1
      else:
        break
      last = heights[left_index]
      left_index -= 1
    right_index = i + 1
    last = heights[i]
    while right_index < len(heights):
      if heights[right_index] <= last:
        tmp += 1
      else:
        break
      last = heights[right_index]
      right_index += 1
    if tmp > out:
      out = tmp
  print out

if __name__ == '__main__':
  main()
