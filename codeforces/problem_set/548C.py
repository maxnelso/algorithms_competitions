import math
import sys
from fractions import gcd

def lcm(a, b):
  """Return lowest common multiple."""
  return a * b // gcd(a, b)

def main():
  m = int(raw_input())
  h1, a1 = map(int, raw_input().split())
  x1, y1 = map(int, raw_input().split())
  h2, a2 = map(int, raw_input().split())
  x2, y2 = map(int, raw_input().split())
  seen1 = {}
  seen1[h1] = 0
  h1_indices = {}
  h1_indices[0] = h1
  index = 0
  current_h1 = h1
  h1_cycle = -1
  while True:
    next_h = ((x1 * current_h1) + y1) % m
    if next_h in seen1:
      h1_cycle = next_h
      break
    current_h1 = next_h
    index += 1
    seen1[next_h] = index
    h1_indices[index] = next_h
  seen2 = {}
  seen2[h2] = 0
  h2_indices = {}
  h2_indices[0] = h2
  index = 0
  current_h2 = h2
  h2_cycle = -1
  while True:
    next_h = ((x2 * current_h2) + y2) % m
    if next_h in seen2:
      h2_cycle = next_h
      break
    current_h2 = next_h
    index += 1
    seen2[next_h] = index
    h2_indices[index] = next_h


  h1_get_to_cycle = 0
  current_h1 = h1
  time_to_good_h1 = -1
  while True:
    if current_h1 == h1_cycle:
      break
    if current_h1 == a1:
      time_to_good_h1 = h1_get_to_cycle
      break
    current_h1 = ((x1 * current_h1) + y1) % m
    del seen1[current_h1]
    h1_get_to_cycle += 1
    raise Exception

  h2_get_to_cycle = 0
  current_h2 = h2
  time_to_good_h2 = -1
  while True:
    if current_h2 == h2_cycle:
      break
    if current_h2 == a2:
      time_to_good_h2 = h2_get_to_cycle
      break
    current_h2 = ((x2 * current_h2) + y2) % m
    del seen2[current_h2]
    h2_get_to_cycle += 1
    raise Exception

  if time_to_good_h1 != -1 and time_to_good_h1 == time_to_good_h2:
    print time_to_good_h1
    return

  if a1 not in seen1 or a2 not in seen2:
    print -1
    return

  t = 0
  step = max(seen1[a1], seen2[a2])
  while True:
    t += step
    if step == seen1[a1]:
      if h1_indices[t % len(seen1)] == a1 and h2_indices[t % len(seen2)] == a2:
        print t
        return

if __name__ == '__main__':
  main()
