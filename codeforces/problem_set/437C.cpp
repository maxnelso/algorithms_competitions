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

const int MAXN = 1005;
set<int> edges[MAXN];
int values[MAXN];
bool marked[MAXN];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> nodes;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &values[i]);
    nodes.push_back(make_pair(values[i], i));
  }
  sort(nodes.rbegin(), nodes.rend());
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].insert(b);
    edges[b].insert(a);
  }

  long long out = 0;
  for (int i = 0; i < n; i++) {
    int next_node = nodes[i].second;
    marked[next_node] = true;
    for (auto& p : edges[next_node]) {
      if (marked[p]) {
        continue;
      }
      out += values[p];
    }
  }

  cout << out;
}
