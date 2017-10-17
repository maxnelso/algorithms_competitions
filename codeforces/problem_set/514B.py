import math
import sys

def to_angle(x, y):
  angle = math.atan2(x, y)
  if angle <= 0:
    angle += math.pi
  return angle


def main():
  n, x0, y0 = map(int, raw_input().split())
  angles = []
  for i in range(n):
    c = map(int, raw_input().split())
    angles.append(to_angle(c[0] - x0, c[1] - y0))
  print len(set(angles))

if __name__ == '__main__':
  main()
