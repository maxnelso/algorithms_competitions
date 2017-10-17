def solve(n, k):
    state = 47
    good = 0
    for step in range(8**n):
        heads = 0
        for i in range(n):
            state = ((state * 1103515245) + 12345) % 2**31
            coin = (state >> 15) & 1  # note: >> is bitwise shift right, & is bitwise and
            heads += coin
        if heads == k: good += 1
    return round(good / 4**n)         # note: / is floating-point division

n = 10
k = 5
for i in range(1, n):
  for j in range(1, i):
    print solve(i, j)
