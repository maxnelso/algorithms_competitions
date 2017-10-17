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
  map<int, set<int>> friends;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    friends[a].insert(b);
    friends[b].insert(a);
  }
  set<int> seen;
  for (auto p : friends) {
    int start = p.first;
    if (seen.find(start) != seen.end()) {
      continue;
    }
    int edges = 0;
    queue<int> q;
    q.push(start);
    seen.insert(start);
    set<int> clique;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      edges += friends[v].size();
      clique.insert(v);
      for (auto edge : friends[v]) {
        if (seen.find(edge) != seen.end()) {
          continue;
        }
        seen.insert(edge);
        q.push(edge);
      }
    }
    if (edges != (((long long) clique.size()) * (clique.size() - 1))) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}
