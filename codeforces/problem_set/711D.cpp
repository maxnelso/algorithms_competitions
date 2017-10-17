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
vector<pair<int, int>> edges[200005];
int v[200005];
int t = 1, st, cycle = 0;

bool dfs(int x, int p, int d) {
  //printf("%d %d %d\n", x, d, v[x]);
  if (v[x]) {
    if (d > v[x]) {
      cycle = d - v[x];
    }
    return true;
  }
  v[x] = d;
  t++;
  for (auto y : edges[x]) {
    if (y.second == p) continue;
    dfs(y.first, y.second, d + 1);
  }
  return false;
}

long long pw[200005];
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    edges[i].push_back({x, i});
    edges[x].push_back({i, i});
  }
  long long ans = 1;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = pw[i - 1] * 2 % 1000000007;
  }
  for (int i = 1; i <= n; i++) {
    if (v[i]) continue;
    t = 0;
    dfs(i, 0, 1);
    int tail = t - cycle;
    //printf("%d %d\n", cycle, tail);
    long long a = pw[cycle] - 2;
    //if (cycle == 1) a = 1;
    if (a < 0) a += 1000000007;
    a *= pw[tail];
    a %= 1000000007;
    ans *= a;
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
