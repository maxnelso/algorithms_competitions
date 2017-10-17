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

const int MAXN = 2005;
const int MOD = (int)(1e9) + 7;

vector<int> adjacent[MAXN];
int a[MAXN];
bool visited[MAXN];
int f[MAXN];
int d, n;

void dfs(int u, int root) {
  visited[u] = true;
  f[u] = 1;
  for (int i = 0; i < adjacent[u].size(); i++) {
    int v = adjacent[u][i];
    if (!visited[v]) {
      if ((a[v] < a[root]) || (a[v] - a[root] > d)) {
        continue;
      }
      if ((a[v] == a[root]) && (v < root)) {
        continue;
      }
      dfs(v, root);
      f[u] = ((long long)(f[u]) * (f[v] + 1)) % MOD;
    }
  }
}

int main () {
  scanf("%d %d", &d, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    adjacent[u].push_back(v);
    adjacent[v].push_back(u);
  }
  int out = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      visited[j] = false;
      f[j] = 0;
    }
    dfs(i, i);
    out += f[i];
    out %= MOD;
  }
  printf("%d", out);
}
