import math

a, b = map(int, raw_input().split())
print ((a * (a + 1) / 2 * b + a) * (b * (b - 1) / 2)) % (1000000007)
