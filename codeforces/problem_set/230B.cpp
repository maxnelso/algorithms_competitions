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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

const int sqrt_limit = 1000001;
bool arr[sqrt_limit];

set<long long> get_prime_squares() {
  for (int i = 2; i *i < sqrt_limit; i++) {
    if (!arr[i]) {
      for (int j = i * i; j < sqrt_limit; j += i) {
        arr[j] = true;
      }
    }
  }

  set<long long> res;
  for (int i = 2; i < sqrt_limit; i++) {
    if (!arr[i]) {
      res.insert((long long) i * i);
    }
  }
  return res;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);

  int n;
  scanf("%d", &n);

  set<long long> sq = get_prime_squares();
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (sq.find(a) != sq.end()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
