import math
import sys

def main():
    n, x = map(int, raw_input().split())
    sad_kids = 0
    ice_cream = x
    for i in range(n):
        sign, num = raw_input().split()
        num = int(num)
        if sign == "+":
            ice_cream += num
        else:
            if ice_cream - num < 0:
                sad_kids += 1
            else:
                ice_cream = ice_cream - num
    print ice_cream, sad_kids


if __name__ == '__main__':
  main()
