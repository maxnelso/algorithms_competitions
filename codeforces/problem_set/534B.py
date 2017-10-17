import math
import sys

def main():
  v1, v2 = map(int, raw_input().split());
  t, d = map(int, raw_input().split());
  t -= 1
  best = 0
  for downslope_time in range(t, -1, -1):
    top_speed = v1 + (d * (t - downslope_time))
    down_speed = v2 + (d * downslope_time)
    if top_speed < down_speed:
      continue
    out = 0
    out += v1
    speed = v1
    for i in range(t - downslope_time):
      speed += d
      if speed > down_speed:
        speed = down_speed
      out += speed
    for i in range(downslope_time):
      speed -= d
      out += speed
    best = max(best, out)
  print best

if __name__ == '__main__':
  main()
