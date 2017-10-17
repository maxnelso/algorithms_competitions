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

int main () {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = 0;
  long long r = 5 * 10e5 * 5 * 10e5;
  long long biggest = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long out = 0;
    for (long long i = 1; i <= n; i++) {
      out += min(m, (mid - 1) / i);
    }

    if (out < k) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << l - 1;
}
