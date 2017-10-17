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

vector<long long> costs;
map<int,vector<int>> edges;
map<int,vector<int>> transpose;
set<int> seen;
stack<int> S;
set<int> assigned;
map<int, vector<int>> connected_components;

void visit(int u) {
  if (seen.find(u) != seen.end()) {
    return;
  }

  seen.insert(u);
  for (auto& v : edges[u]) {
    visit(v);
  }

  S.push(u);
}

void assign_node(int u, int root) {
  if (assigned.find(u) != assigned.end()) {
    return;
  }
  assigned.insert(u);
  connected_components[root].push_back(u);
  for (auto& v : transpose[u]) {
    assign_node(v, root);
  }
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    costs.push_back(a);
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a - 1].push_back(b - 1);
    transpose[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++) {
    visit(i);
  }

  while (!S.empty()) {
    int node = S.top();
    S.pop();
    assign_node(node, node);
  }

  long long out_a = 0;
  long long out_b = 1;
  const int MOD = 1000000007;
  for (int i = 0; i < n; i++) {
    if (connected_components.find(i) == connected_components.end()) {
      continue;
    }
    long long tmp = LLONG_MAX;
    for (int j = 0; j < connected_components[i].size(); j++) {
      tmp = min(tmp, costs[connected_components[i][j]]);
    }
    int c = 0;
    for (int j = 0; j < connected_components[i].size(); j++) {
      if (costs[connected_components[i][j]] == tmp) {
        c++;
      }
    }
    out_b = (out_b * c) % MOD;
    out_a += tmp;
  }
  cout << out_a << " " << out_b;
}
