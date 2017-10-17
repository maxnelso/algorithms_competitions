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

#define MOD 1000000007

using namespace std;
int memo[105][2];
int n, k, d;

int helper(int sum, bool need) {
  if (sum < 0) {
    return 0;
  }
  if (sum == 0) {
    return !need;
  }
  if (memo[sum][need] != -1) {
    return memo[sum][need];
  }
  memo[sum][need] = 0;
  for (int i = 1; i <= min(k, sum); i++) {
    if (i < d) {
      memo[sum][need] = (memo[sum][need] + helper(sum - i, need)) % MOD;
    } else {
      memo[sum][need] = (memo[sum][need] + helper(sum - i, false)) % MOD;
    }
  }
  return memo[sum][need];
}

int main () {
  memset(memo, -1, sizeof(memo));
  scanf("%d %d %d", &n, &k, &d);
  helper(n, true);
  printf("%d", memo[n][true]);
  setvbuf(stdout, NULL, _IONBF, 0);
}
