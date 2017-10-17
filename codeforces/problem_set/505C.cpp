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

const int M = 30001;

map<int, int> treasure;
int dp[M][250*2];
bool used[M][250*2] = {};
int d;

int solve(int i, int j) {
  int jj = j - (d - 250);
  if (i >= M) {
    return 0;
  }
  if (used[i][jj]) {
    return dp[i][jj];
  }

  used[i][jj] = true;
  int out;
  if (j == 1) {
    out = treasure[i] + max(solve(i + j, j), solve(i + j + 1, j + 1));
  } else {
    out = treasure[i] + max(solve(i + j - 1, j - 1), max(solve(i + j, j), solve(i + j + 1, j + 1)));
  }

  dp[i][jj] = out;
  return out;
}

int main () {
  int n;
  scanf("%d %d", &n, &d);

  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    treasure[a]++;
  }

  printf("%d", solve(d, d));
}
