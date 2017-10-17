import math

t, k = map(int, raw_input().split())
memo = {}
for i in range(t):
  l, r = map(int, raw_input().split())
  count = 0
  for j in range(l, r + 1):
    if j in memo:
      count = count + memo[j]
      count = count % 1000000007
    else:
      tmp = 0
      for white_ks in range(0, j + 1, k):
        red_count = j - white_ks
        tmp = tmp + math.factorial(red_count + white_ks / k) / (math.factorial(red_count) * math.factorial(white_ks / k))
        tmp = tmp % 1000000007
      memo[j] = tmp
      count = count + tmp
      count = count % 1000000007
  print count

