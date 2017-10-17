import math
import sys

def main():
  n, l, v1, v2, k = map(int, raw_input().split())
  v1 = float(v1)
  v2 = float(v2)
  l = float(l)
  best_time = float("inf")
  walkers_l = 0
  walkers = max(0, n - k)
  time = 0
  while walkers > 0:
    print "NEW"
    time += (l - walkers_l) / v2 # Bus to the end
    walkers_l += time * v1 # Walkers time
    collision_time = (l - walkers_l) / (v1 + v2)
    print time, collision_time, walkers_l
    time += collision_time
    walkers_l += collision_time * v1
    print time, collision_time, walkers_l
    walkers -= k

  print time + ((l - walkers_l) / v2)

if __name__ == '__main__':
  main()
