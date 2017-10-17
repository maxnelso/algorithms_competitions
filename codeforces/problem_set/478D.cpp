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
const int MOD = int(1e9) + 7;
int f[200200];

int main () {
  int r, g;
  cin >> r >> g;
  f[0] = 1;
  long long out = 0;
  for (int h = 1; h <= 1000; h++) {
    bool can_build = false;
    int ways = 0;
    for (int i = r; i >= 0; i--) {
      if (i >= h) {
        f[i] += f[i - h];
        if (f[i] >= MOD) {
          f[i] -= MOD;
        }
      }

      if (f[i] && i + g >= h * (h + 1) / 2) {
        can_build = true;
        ways += f[i];
        if (ways >= MOD) {
          ways -= MOD;
        }
      }
    }
    if (!can_build) {
      break;
    }
    out = ways;
  }
  cout << out;
}
