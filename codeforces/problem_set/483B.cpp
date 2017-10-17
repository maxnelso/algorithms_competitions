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

const long long MAXN = 5000000000;

int main () {
  long long c1, c2, x, y;
  cin >> c1 >> c2 >> x >> y;

  long long l = 1;
  long long r = MAXN;
  while (l <= r) {
    long long m = (l + r) / 2;

    long long both_can_use = m - (m / x + m / y - m / (y * x));
    long long c1_can_use = m / y - (m / (y * x));
    long long c2_can_use = m / x - (m / (y * x));
    long long c1_needs = c1 - c1_can_use;
    if (c1_needs > 0) {
      both_can_use -= c1_needs;
    }
    long long c2_needs = c2 - c2_can_use;
    if (c2_needs > 0) {
      both_can_use -= c2_needs;
    }
    if (both_can_use < 0) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  cout << l;
}
