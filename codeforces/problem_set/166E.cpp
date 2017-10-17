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

long long dp[10000005];

int main () {
  long long n;
  cin >> n;

  long long out = 1;
  const int MOD = 1000000007;
  dp[2] = 3;
  if (n == 2) {
    printf("3");
    return 0;
  }
  long long mult = 3;
  for (int i = 3; i <= n; i++) {
    mult  = (mult * 3) % MOD;
    dp[i] = (mult - dp[i - 1]) % MOD;
    if (dp[i] < 0) {
      dp[i] += MOD;
    }
  }
  cout << dp[n];
}
