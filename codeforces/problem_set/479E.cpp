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

#define MOD 1000000007

int dp[5010][5010];
int sums[5010][5010];

void compute_sums(int x, int n) {
  for (int i = 1; i <= n; i++) {
    sums[i][x] = (sums[i-1][x] + dp[i][x]) % MOD;
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, a, b, k;
  scanf("%d %d %d %d", &n, &a, &b, &k);
  dp[a][0] = 1;
  compute_sums(0, n);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < b; j++) {
      dp[j][i] = (sums[(b + j - 1) / 2][i - 1] - dp[j][i-1] + MOD) % MOD;
    }
    for (int j = b + 1; j <= n; j++) {
      dp[j][i] = ((sums[n][i - 1] - sums[(j + b + 2) / 2 - 1][i-1] + MOD) % MOD - dp[j][i-1] + MOD) % MOD;
    }
    compute_sums(i, n);
  }
  printf("%d", sums[n][k]);
}
