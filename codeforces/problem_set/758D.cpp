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
  int base;
  scanf("%d", &base);

  char K[61];
  scanf("%s", K);
  int l = (int) strlen(K);
  vector<long long> dp(l + 1, LLONG_MAX);
  dp[0] = 0;
  for (int i = 0; i < l; i++) {
    long long x = dp[i];
    if (x == LONG_MAX) {
      continue;
    }
    long long num = 0;
    for (int j = i + 1; j <= l; j++) {
      num = num * 10 + (K[j - 1] - '0');
      if (num >= base || (double)x * base + num > 1.1e18) {
        break;
      }
      if (x * base + num < dp[j]) {
        dp[j] = x * base + num;
      }
      if (K[i] == '0') {
        break;
      }
    }
  }
  cout << dp[l];
}
