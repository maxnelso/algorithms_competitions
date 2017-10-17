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
#define INF 1000000009

int dist[1000010];
int previous[1000010];
int id = 0;
int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  map<int, vector<pair<int,int>> > road_edges;
  map<int, vector<pair<int,int>> > train_edges;
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int u, v, x;
    scanf("%d %d %d", &u, &v, &x);
    if (road_edges.find(u) != road_edges.end()) {
      road_edges[u].push_back(make_pair(v, x));
    } else {
      vector<pair<int, int>> edge;
      edge.push_back(make_pair(v, x));
      road_edges[u] = edge;
    }
    // reverse
    if (road_edges.find(v) != road_edges.end()) {
      road_edges[u].push_back(make_pair(u, x));
    } else {
      vector<pair<int, int>> edge;
      edge.push_back(make_pair(u, x));
      road_edges[v] = edge;
    }
  }
  for (int i = 0; i < k; i++) {
    int s, y;
    scanf("%d %d", &s, &y);
    if (train_edges.find(s) != train_edges.end()) {
      train_edges[s].push_back(make_pair(1, y));
    } else {
      vector<pair<int, int>> edge;
      edge.push_back(make_pair(1, y));
      train_edges[s] = edge;
    }
    // reverse
    if (train_edges.find(1) != train_edges.end()) {
      train_edges[1].push_back(make_pair(s, y));
    } else {
      vector<pair<int, int>> edge;
      edge.push_back(make_pair(s, y));
      train_edges[1] = edge;
    }
  }
  priority_queue<pair<int,int>> q;
  dist[1] = 0;
  q.push(make_pair(0, 1));
  for (int i = 2; i <= n; i++) {
    dist[i] = INF;
    previous[i] = -1;
    q.push(make_pair(INF, i));
  }
  while (!q.empty()) {
    pair<int, int> u = q.top();
    q.pop();
    for (int i = 0; i < road_edges[u.second].size(); ++i) {
      int d = dist[u.second] + road_edges[u.second][i].second;
      printf("Looking at %d: with edge to %d\n", u.second, road_edges[u.second][i]);
    }
  }
}
