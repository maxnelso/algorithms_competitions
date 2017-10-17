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

int main () {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> nodes;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    nodes.push_back(make_pair(a, b));
    if (a == 1) {
      q.push(i);
    }
  }

  vector<pair<int, int>> edges;
  set<pair<int, int>> seen;
  while (!q.empty()) {
    int i = q.front();
    // printf("Looking at %d\n", i);
    q.pop();
    pair<int, int>& node = nodes[i];
    if (node.first == 0) {
      continue;
    }
    // printf("node %d %d\n", node.first, node.second);
    int parent = node.second;
    if (node.first == 1) {
      edges.push_back(make_pair(i, parent));
    }
    pair<int, int>& parent_node = nodes[parent];
    parent_node.first--;
    parent_node.second ^= i;
    if (parent_node.first == 1) {
      q.push(parent);
    }
  }

  printf("%d\n", edges.size());
  for (int i = 0; i < edges.size(); i++) {
    printf("%d %d\n", edges[i].first, edges[i].second);
  }

}
