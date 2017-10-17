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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct Graph {
  map<int, vector<int>> edges;
};

bool bfs(Graph g, int start, int destination) {
  set<int> seen;
  if (g.edges.find(start) == g.edges.end() ||
      g.edges.find(destination) == g.edges.end()) {
    return false;
  }
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    if (node == destination) {
      return true;
    }
    q.pop();
    seen.insert(node);
    for (int neighbor : g.edges[node]) {
      if (seen.find(neighbor) == seen.end()) {
        q.push(neighbor);
      }
    }
  }
  return false;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  map<int, Graph> color_map;
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (color_map.find(c) == color_map.end()) {
      Graph g;
      g.edges[a] = {b};
      g.edges[b] = {a};
      color_map[c] = g;
    } else {
      Graph& g = color_map[c];
      if (g.edges.find(a) == g.edges.end()) {
        g.edges[a] = {b};
      } else {
        g.edges[a].push_back(b);
      }
      if (g.edges.find(b) == g.edges.end()) {
        g.edges[b] = {a};
      } else {
        g.edges[b].push_back(a);
      }
    }
  }
  int queries;
  scanf("%d", &queries);
  for (int i = 0; i < queries; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int out = 0;
    for (int j = 1; j <= 100; j++) {
      if (color_map.find(j) != color_map.end()) {
        if (bfs(color_map[j], u, v)) {
          out++;
        }
      }
    }
    printf("%d\n", out);
  }
}
