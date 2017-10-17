import math
import sys

def main():
  n, m, w = map(int, raw_input().split())
  flowers = map(int, raw_input().split())
  waters = [0] * 100005;
  high = 2000000000
  low = 1
  best = 1
  while low <= high:
    mid = (low + high) / 2
    days_needed = 0
    waters_active = 0
    for i in range(n):
      if i >= w:
        waters_active -= waters[i - w]
      needed = max(0, mid - flowers[i] - waters_active)
      waters[i] = needed
      waters_active += waters[i]
      days_needed += waters[i]
    if days_needed <= m:
      best = max(best, mid)
      low = mid + 1
    else:
      high = mid - 1
  print best

if __name__ == '__main__':
  main()
