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

double dfs(int node, int parent, int d) {
  if (edges[node].size() == 1 && parent != -1) {
    return d;
  }
  double p;
  if (parent == -1) {
    p = 1.0f / edges[node].size();
  } else {
    p = 1.0f / (edges[node].size() - 1);
  }
  double out = 0;
  for (int i = 0; i < edges[node].size(); i++) {
    if (edges[node][i] != parent) {
      double a = dfs(edges[node][i], node, d + 1);
      out += p * a;
    }
  }
  return out;
}

int main () {
  int n;
  scanf("%d", &n);
  edges.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  printf("%.08f", dfs(0, -1, 0));
}
