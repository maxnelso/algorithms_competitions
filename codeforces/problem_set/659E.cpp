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

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  map<int, vector<int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  set<int> seen;
  int out = 0;
  for (int i = 1; i <= n; i++) {
    if (seen.find(i) != seen.end()) {
      continue;
    }
    vector<int> connected_component;
    connected_component.push_back(i);
    queue<int> q;
    q.push(i);
    seen.insert(i);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (int p: edges[a]) {
        if (seen.find(p) != seen.end()) {
          continue;
        }
        connected_component.push_back(p);
        seen.insert(p);
        q.push(p);
      }
    }

    int num_edges = 0;
    for (int j = 0; j < connected_component.size(); j++) {
      num_edges += edges[connected_component[j]].size();
    }
    num_edges /= 2;
    out += num_edges == connected_component.size() - 1;
  }
  printf("%d", out);
}
