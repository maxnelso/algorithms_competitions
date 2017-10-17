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

long long dp[10000000];

int main () {
  long long n, x, y;
  cin >> n >> x >> y;
  dp[0] = 0;
  for (long long i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      dp[i] = min(dp[i - 1] + x, dp[i / 2] + y);
    } else {
      dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + x + y);
    }
  }
  cout << dp[n];

}
