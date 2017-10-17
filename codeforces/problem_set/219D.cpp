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

const int MAXN = 2 * 100000 + 5;

int ans[MAXN];
int t;
vector<pair<int, int>> adj[MAXN];

void dfs(int parent, int v, int green, int dist) {
  ans[v] = 2 * green - dist;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i].first + adj[v][i].second - v;
    if (u == parent) {
      continue;
    }
    if (adj[v][i].first == v) { // green
      dfs(v, u, green + 1, dist + 1);
    } else { // red
      dfs(v, u, green, dist + 1);
      t++;
    }
  }
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(make_pair(a, b));
    adj[b].push_back(make_pair(a, b));
  }

  dfs(0, 1, 0, 0);
  for (int i = 1; i <= n; i++) {
    ans[i] += t;
  }

  int out = 10000000;
  for (int i = 1; i <= n; i++) {
    out = min(out, ans[i]);
  }
  printf("%d\n", out);

  for (int i = 1; i <= n; i++) {
    if (ans[i] == out) {
      printf("%d ", i);
    }
  }
}
