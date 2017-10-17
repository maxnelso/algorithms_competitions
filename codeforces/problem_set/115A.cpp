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
  vector<set<int>> edges(n + 1);
  vector<int> roots;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a == -1) {
      roots.push_back(i + 1);
    } else {
      edges[a].insert(i + 1);
    }
  }

  int out = 0;
  for (int i = 0; i < roots.size(); i++) {
    queue<pair<int, int>> q;
    q.push(make_pair(roots[i], 1));
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      out = max(out, p.second);
      for (auto& child : edges[p.first]) {
        q.push(make_pair(child, p.second + 1));
      }
    }
  }

  printf("%d", out);
}
