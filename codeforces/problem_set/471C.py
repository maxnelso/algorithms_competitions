import math

def num_cards(f):
  return 3*f*(f + 1) / 2 - f

n = int(raw_input())
out = 0
floors = 1
while num_cards(floors) <= n:
  if (n + floors) % 3 == 0:
    out += 1
  floors += 1

print out
