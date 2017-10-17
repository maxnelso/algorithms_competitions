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

long long dp[2010][2010]; // length x ending with
const int MOD = 1000000007;
const int MAXN = 2000;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  dp[0][1] = 1;
  for (int i = 0; i <= MAXN; i++) {
    for (int j = 1; j <= MAXN; j++) {
      for (int l = j; l <= MAXN; l += j) {
        dp[i + 1][l] += dp[i][j];
        dp[i + 1][l] = dp[i + 1][l] % MOD;
      }
    }
  }

  long long out = 0;
  for (int i = 1; i <= n; i++) {
    out += dp[k][i];
    out %= MOD;
  }
  cout << out;
}
