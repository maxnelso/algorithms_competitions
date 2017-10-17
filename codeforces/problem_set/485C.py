import math

n = int(raw_input())

for i in range(n):
  l, r = map(int, raw_input().split())
  l = "{0:b}".format(l)
  r = "{0:b}".format(r)
  if r.count("1") == len(r):
    print int(r, 2)
  elif l == r:
    print int(r, 2)
  else:
    while len(l) < len(r):
      l = "0" + l
    out = ""
    flag = False
    for i in range(len(l)):
      if l[i] == "0" and r[i] == "1":
        out += "0"
        for j in range(len(l) - i - 1):
          out += "1"
        flag = True
      else:
        out += l[i]
      if flag:
        break
    print int(out, 2)
