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

const int MAXN = 200005;
int a[MAXN];
vector<int> g[MAXN];
long long answer = LLONG_MIN;

pair<long long, long long> dfs(int v, int parent) {
  long long maxx = LLONG_MIN;
  long long sum = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int next_node = g[v][i];
    if (next_node == parent) {
      continue;
    }
    auto ret = dfs(next_node, v);
    sum += ret.second;
    if (maxx != LLONG_MIN) {
      answer = max(answer, ret.first + maxx);
    }
    maxx = max(maxx, ret.first);
  }
  maxx = max(maxx, a[v] + sum);
  return make_pair(maxx, a[v] + sum);
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0, -1);
  if (answer == LLONG_MIN) {
    printf("Impossible\n");
    return 0;
  }
  cout << answer;
}
