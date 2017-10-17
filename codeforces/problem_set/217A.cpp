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
  vector<pair<int, int>> coords;
  map<int, int> xs;
  map<int, int> ys;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    coords.push_back(make_pair(a, b));
  }

  vector<bool> marked(n);
  int out = 0;
  for (int i = 0; i < n; i++) {
    if (marked[i]) {
      continue;
    }
    out++;
    stack<int> s;
    s.push(i);
    while (!s.empty()) {
      int node = s.top();
      s.pop();
      int x1 = coords[node].first;
      int y1 = coords[node].second;
      marked[node] = true;
      for (int j = 0; j < n; j++) {
        if (marked[j]) {
          continue;
        }
        int x2 = coords[j].first;
        int y2 = coords[j].second;
        if (x1 == x2 || y1 == y2) {
          s.push(j);
        }
      }
    }
  }
  printf("%d", out - 1);
}
