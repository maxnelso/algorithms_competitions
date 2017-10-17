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

const int MAXN = 1000000000 + 10;

vector<long long> primes_below(long long n) {
  vector<bool> sieve(n + 1);
  fill(sieve.begin(), sieve.end(), true);
  vector<long long> primes;
  for (long long p = 2; p <= n; ++p) {
    if (sieve[p]) {
      primes.push_back(p);
      for (long long i = p*p; i <= n; i += p) {
        sieve[i] = false;
      }
    }
  }
  return primes;
}


vector<long long> small_primes = primes_below(100000);
set<long long> small_primes_set(small_primes.begin(), small_primes.end());
long long _smallprimeset = 100000;

bool is_prime(long long n, long long precision = 7) {
  if (n == 1 || n % 2 == 0) {
    return false;
  } else if (n < 1) {
    return false;
  } else if (n < _smallprimeset) {
    return small_primes_set.find(n) != small_primes_set.end();
  }

  long long d = n - 1;
  long long s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (long long repeat = 0; repeat < precision; ++repeat) {
    long long a = (rand() % (n - 2 - 2)) + 2;
    long long x = (long long) pow(a, d) % n;

    if (x == 1 || x == n - 1) {
      continue;
    }

    for (long long r = 0; r < s - 1; ++r) {
      x = (long long) pow(x, 2) % n;
      if (x == 1) {
        return false;
      }
      if (x == n - 1) {
        break;
      }
    }
  }
  return true;
}


int main () {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2 == 0) {
      if (a == 2) {
        printf("-1\n");
      } else {
        printf("%d\n", a / 4);
      }
    } else {
      if (a < 9 || a == 11) {
        printf("-1\n");
      } else {
        printf("%d\n", a / 4 - 1);
      }
    }
  }
}
