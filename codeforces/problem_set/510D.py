import math
import sys
import fractions

def main():
  n = int(raw_input())
  lengths = map(int, raw_input().split())
  costs = map(int, raw_input().split())
  ads = { 0 : 0 }
  for v in zip(lengths, costs):
    for item in ads.items():
      a = fractions.gcd(item[0], vi[0])
      ads[a] = min(ads.get(a, 100000000), item[1] + vi[1])
  print ads.get(1, -1)

if __name__ == '__main__':
  main()
