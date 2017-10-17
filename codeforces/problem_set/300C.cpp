#include <bitset>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int MOD = 1000000007;

long long fact[1000005];

long long qpow(long long a, long long b) {
  long long x = 1, y = a;
  while (b) {
    if (b % 2) {
      x = x * y % MOD;
    }
    y = y * y % MOD;
    b /= 2;
  }
  return x;
}

long long inv(long long n) {
  return qpow(n, MOD - 2);
}

int main () {
  int a, b, n;
  scanf("%d %d %d", &a, &b, &n);

  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  long long out = 0;
  for (int i = 0; i <= n; i++) {
    int m = a * i + (n - i) * b;
    bool flag = true;
    while (m) {
      flag &= (m % 10 == a || m % 10 == b);
      m /= 10;
    }

    if (flag) {
      out += ((fact[n] * inv(fact[n - i]) % MOD) * inv(fact[i])) % MOD;
      out %= MOD;
    }
  }

  cout << out;
}
