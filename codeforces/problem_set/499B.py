import math
import sys

def main():
  n, m = map(int, raw_input().split())
  words = {}
  for i in range(m):
    a, b = raw_input().split()
    words[a] = b
  lecture = raw_input().split()
  for word in lecture:
    if len(words[word]) < len(word):
      print words[word],
    else:
      print word,

if __name__ == '__main__':
  main()
