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

const int MAXN = 5001;

vector<long long> sums;
long long dp[MAXN][MAXN];
vector<int> nums;
int n, m, k;

long long get_sum(int l, int r) {
  if (l == 0) {
    return sums[r];
  }
  return sums[r] - sums[l - 1];
}

long long solve(int index, int left) {
  if (dp[index][left] != -1) {
    return dp[index][left];
  }

  if (left == 0) {
    return 0;
  }

  if (left * m >= n - index) {
    dp[index][left] = get_sum(index, n - 1);
  } else {
    dp[index][left] = max(solve(index + 1, left), solve(index + m, left - 1) + get_sum(index, index + m - 1));
  }

  return dp[index][left];
}

int main () {
  memset(dp, -1, sizeof(dp[0][0]) * MAXN * MAXN);
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
    if (sums.empty()) {
      sums.push_back(a);
    } else {
      sums.push_back(a + sums[i - 1]);
    }
  }

  solve(0, k);

  cout << dp[0][k];
}
