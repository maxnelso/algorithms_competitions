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
#include <iterator>
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int primes[100050];

int main () {
  int n;
  scanf("%d", &n);
  for (long long i = 2; i <= n + 1; i++) {
    if (!primes[i]) {
      for (long long p = i * i; p <= n + 1; p += i) {
        if (i * i <= n + 1) {
          primes[p] = 1;
        }
      }
    }
  }

  if (n <= 2) {
    printf("1\n");
    for (int i = 0; i < n; i++) {
      printf("1 ");
    }
    return 0;
  }

  printf("2\n");
  for (int i = 0; i < n; i++) {
    if (primes[i + 2]) {
      printf("1 ");
    } else {
      printf("2 ");
    }
  }
}
