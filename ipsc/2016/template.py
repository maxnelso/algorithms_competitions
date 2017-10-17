import math
import itertools
import sys

FILENAME = 'a2'

f = open(FILENAME + '.in', 'r')
tests = int(f.readline())
sys.stdout = open(FILENAME + '.out', 'w')
for x in range(tests):
    line = f.readline()
    line = f.readline()
    words = line.split()
    done = False
    final_word = ""
    for i in range(10):
        for j in range(4):
            for k in range(10):
                if i == k:
                    continue
                test_str = words[i][0:j+1]
                test_word = words[k][4 - (j + 1):]
                if (test_word == test_str):
                    for z in range(10):
                        if z == i or z == k:
                            continue
                        final_word += words[z]
                    final_word += words[k]
                    final_word += words[i][j + 1:]
                    done = True
                if done:
                    break
            if done:
                break
        if done:
            break
    while len(final_word) < 39:
        final_word += 'A'
    for word in words:
        if word not in final_word:
            print "============="
            break
    print final_word
