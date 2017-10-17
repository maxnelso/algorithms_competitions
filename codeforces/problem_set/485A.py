import math

a, m = map(int, raw_input().split());

for i in range(100000):
  if a % m == 0:
    print "Yes"
    exit()
  a = a + (a % m)
print "No"
