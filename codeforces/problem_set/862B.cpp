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

vector<vector<int>> edges;
int odd_depth = 0;
int even_depth = 0;
set<int> odd_depths;
set<int> even_depths;

void dfs(int node, int depth, int parent)  {
  if (depth % 2 == 0) {
    even_depth++;
    even_depths.insert(node);
  } else {
    odd_depth++;
    odd_depths.insert(node);
  }
  for (int i = 0; i < edges[node].size(); i++) {
    if (edges[node][i] == parent) {
      continue;
    }
    dfs(edges[node][i], depth + 1, node);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  edges.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  long long out = 0;
  dfs(1, 0, 0);
  for (auto& p : odd_depths) {
    out += (long long) even_depth - (long long) edges[p].size();
  }
  for (auto& p : even_depths) {
    out += (long long) odd_depth - (long long) edges[p].size();
  }
  cout << out / 2;
}
