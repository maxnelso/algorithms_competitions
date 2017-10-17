import math

s = sum(map(int, raw_input().split()))
if s == 0:
  print -1
elif s % 5 == 0:
  print s / 5
else:
  print -1
