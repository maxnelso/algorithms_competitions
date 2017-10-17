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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> colors;
  map<int, set<int>> neighbors;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    colors.push_back(a);
    neighbors[a] = {};
  }

  map<int, vector<int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (auto& edge : edges) {
    for (auto& neighboring : edge.second) {
      if (colors[edge.first] != colors[neighboring]) {
        neighbors[colors[edge.first]].insert(colors[neighboring]);
      }
    }
  }
  int max_color = 1000000;
  int max_card = -1;
  for (auto& color : neighbors) {
    int card = color.second.size();
    if (card > max_card || (card == max_card && color.first < max_color)) {
      max_color = color.first;
      max_card = color.second.size();
    }
  }
  printf("%d", max_color);
}
