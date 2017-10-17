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

vector<vector<int>> edges;
long long k, x;
long long n, m;

const long long MOD = 1000000000 + 7;

long long solve(long long node, long long parent, bool parent_was_high, long long high_security) {
  long long out_high = 0;
  long long out_other = 0;
  // high
  if (!parent_was_high && high_security < x) {
    out_high = k > 1 ? 1 : 0;
    for (int i = 0; i < edges[node].size(); i++) {
      if (edges[node][i] == parent) {
        continue;
      }
      out_high *= solve(edges[node][i], node, true, high_security + 1);
      out_high %= MOD;
    }
  }
  // other
  if (parent_was_high) {
    out_other = k - 1;
  } else {
    out_other = m - 1;
  }
  for (int i = 0; i < edges[node].size(); i++) {
    if (edges[node][i] == parent) {
      continue;
    }
    out_other *= solve(edges[node][i], node, false, high_security);
    out_other %= MOD;
  }
  cout << "Looking at " << node << " " << parent << " " << parent_was_high << " " << high_security << endl;
  cout << out_high << " " << out_other << endl;
  return out_high + out_other;
}

int main () {
  cin >> n >> m;
  edges.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  cin >> k >> x;
  if (m == 1) {
    printf("0");
    return 0;
  }
  cout << solve(0, -1, false, 0);
}
