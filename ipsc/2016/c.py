import math
import itertools
import sys
is_max = True
fact = []


MOD = 10**9 + 9

def factmod(n):
    return fact[n]
        
def factdp(n):
    ans = 1
    for x in xrange(n):
        ans = (ans*(x+1)) % MOD
        fact[x] = ans;
        
        
# Fill up fact
factdp(10**6)


# Multinomial
def blah(lengths):
    denom = 1
    for i in range(len(lengths)):
        denom = (denom *factmod(lengths[i]));
    numer = 0
    for i in range(len(lengths)):
        numer += lengths[i]
    return (factmod(numer) / denom) % MOD;
  
def blah3(cycles):
    lengths = []
    for i in range(len(cycles)):
        lengths.append(len(cycles[i]))
    return blah(lengths)

dp = {1:1, 2:1}
def blah2(n):
    if n in dp:
      return dp[n]
    val = 0
    for x in xrange((n-1)/2):
        if x == 0:
             val += n * blah2(n-1)
        lengths = [x, n-x-1]
        val = ( val + ( ( ( blah(lengths) * blah(x) ) % MOD ) * blah(n-x-1) ) % MOD ) % MOD
    dp[n] = val
    return val

FILENAME = 'c1'


f = open(FILENAME + '.in', 'r')
tests = int(f.readline())

if is_max:
    sys.stdout = open(FILENAME + '.out', 'w')
else:
    outf = open(FILENAME + '.out', 'w')
for test in range(tests):
    f.readline()
    n = int(f.readline())
    permutation = map(int, f.readline().split())
    cycles = []
    seen = {}
    for i in range(len(permutation)):
        if permutation[i] in seen:
            continue
        new_cycle = []
        index = permutation[i] - 1
        seen[i] = True
        if i + 1 == permutation[i]:
            continue

        while not permutation[index] in seen:
            new_cycle.append(index)
            seen[permutation[index]] = True
            index = permutation[index] - 1
        cycles.append(new_cycle)

    out = blah(cycles) % MOD;
    for i in range(len(cycles)):
        out = (out * (factmod(len(cycles[i])) / 2)) % MOD
    print permutation
    print cycles
    print out
    if not is_max:
        outf.write(str(out)+'\n')
if not is_max:
    outf.close()
