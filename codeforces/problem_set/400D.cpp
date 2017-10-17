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

const int INF = 0x39393939;

struct edge {
  int node_id;
  int cost;
};

struct node {
  int type;
  vector<edge> neighbors;
};

vector<node> nodes;
vector<int> total_types;

const int MAXN = 505;
int d[MAXN][MAXN];
int test[MAXN];

int n, m, k;

class Compare {
  public:
    bool operator()(edge e1, edge e2) {
      return e1.cost < e2.cost;
    }
};

void do_dijkstra(int node_id) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int starting_type = nodes[node_id].type;
  pq.push(make_pair(0, node_id));
  d[starting_type][starting_type] = 0;
  while (!pq.empty()) {
    int node = pq.top().second;
    int node_type = nodes[node].type;
    pq.pop();
    for (int i = 0; i < nodes[node].neighbors.size(); i++) {
      int neighbor = nodes[node].neighbors[i].node_id;
      int neighbor_type = nodes[neighbor].type;
      int cost = nodes[node].neighbors[i].cost;

      if (d[starting_type][neighbor_type] > d[starting_type][node_type] + cost) {
        d[starting_type][neighbor_type] = d[starting_type][node_type] + cost;
        d[neighbor_type][starting_type] = d[starting_type][node_type] + cost;
        pq.push(make_pair(d[starting_type][neighbor_type], neighbor));
      }
    }
  }
}

bool do_bfs(int node_id) {
  int start_type = nodes[node_id].type;
  queue<int> q;
  q.push(node_id);
  set<int> seen;
  int type_count = 0;
  seen.insert(node_id);
  while (!q.empty()) {
    node bacteria = nodes[q.front()];
    q.pop();
    int type = bacteria.type;
    type_count += type == start_type;
    for (int i = 0; i < bacteria.neighbors.size(); i++) {
      edge e = bacteria.neighbors[i];
      if (e.cost != 0) {
        continue;
      }
      if (seen.find(e.node_id) != seen.end()) {
        continue;
      }
      seen.insert(e.node_id);
      q.push(e.node_id);
    }
  }
  return type_count == total_types[start_type];
}

int main () {
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      d[i][j] = INF;
    }
  }

  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    total_types.push_back(a);
    for (int j = 0; j < a; j++) {
      node bacteria;
      bacteria.type = i;
      nodes.push_back(bacteria);
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b, cost;
    scanf("%d %d %d", &a, &b, &cost);
    a--;
    b--;
    edge e1;
    e1.node_id = b;
    e1.cost = cost;
    nodes[a].neighbors.push_back(e1);
    edge e2;
    e2.node_id = a;
    e2.cost = cost;
    nodes[b].neighbors.push_back(e2);
    d[nodes[a].type][nodes[b].type] = min(d[nodes[a].type][nodes[b].type], cost);
    d[nodes[b].type][nodes[a].type] = min(d[nodes[b].type][nodes[a].type], cost);
  }

  set<int> seen;
  for (int i = 0; i < n; i++) {
    int type = nodes[i].type;
    if (seen.find(type) != seen.end()) {
      continue;
    }
    seen.insert(type);
    bool clean = do_bfs(i);
    if (!clean) {
      printf("No");
      return 0;
    }
    d[type][type] = 0;
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < k; l++) {
        if (d[j][i] + d[i][l] < d[j][l]) {
          d[j][l] = d[j][i] + d[i][l];
        }
      }

    }
  }

  printf("Yes\n");
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (d[i][j] == INF) {
        d[i][j] = -1;
      }
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}
