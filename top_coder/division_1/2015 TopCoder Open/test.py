import itertools

def beauty(s):
  for i in range(len(s) - 1):
    if s[i] == s[i + 1]:
      return False
  return True

for n in range(2, 10):
  for cnt in range(n * (n + 1) / 2 + 1):
    strings = ["".join(seq) for seq in itertools.product("01", repeat=n)]
    total = 0
    for s in strings:
      b = 0
      for size in range(1, n + 1):
        for start in range(0, n - size + 1):
          if beauty(s[start:start+size]):
            b += 1
      if b == cnt:
        print s
        total += 1
    print "For n = {0} and cnt = {1}, total = {2}".format(n, cnt, total)
