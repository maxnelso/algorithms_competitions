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

const int MAXN = 100005;

vector<vector<int>> edges;
vector<long long> nums;
set<int> seen;
long long par[MAXN];
long long inc[MAXN];
long long decc[MAXN];

void solve(int node) {
  seen.insert(node);
  long long cinc = 0;
  long long cdecc = 0;
  for (int i = 0; i < edges[node].size(); i++) {
    int next = edges[node][i];
    if (par[next] == 0) {
      par[next] = node;
      solve(next);
      cinc = max(cinc, inc[next]);
      cdecc = max(cdecc, decc[next]);
    }
  }
  long long val = nums[node];
  val += cinc;
  val -= cdecc;
  if (val > 0) {
    cdecc += val;
  } else {
    cinc -= val;
  }
  decc[node] = cdecc;
  inc[node] = cinc;
}

int main () {
  int n;
  scanf("%d", &n);
  edges.resize(n + 4);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  nums.push_back(0);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }

  par[1] = 1;
  solve(1);
  cout << fixed << inc[1] + decc[1];
}
