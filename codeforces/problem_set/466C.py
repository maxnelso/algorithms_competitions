import math

n = int(raw_input())
nums = map(int, raw_input().split())
cnt = [0] * 1000010

if sum(nums) % 3 != 0:
  print 0
  exit()
s = sum(nums) / 3
ss = 0
for i in range(n-1, -1, -1):
  ss += nums[i]
  if ss == s:
    cnt[i] = 1
for i in range(n-2, -1, -1):
  cnt[i] += cnt[i+1]
ans = 0
ss = 0
for i in range(0, n - 2):
  ss += nums[i]
  if ss == s:
    ans += cnt[i+2]
print ans
