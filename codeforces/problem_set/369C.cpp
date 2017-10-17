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

bool whites[100005];
int dp[100005];
map<int, vector<int>> roads;

int calc(int v, int p) {
  dp[v] += whites[v];
  for (int i = 0; i < roads[v].size(); i++) {
    if (p == roads[v][i]) {
      continue;
    }
    dp[v] += calc(roads[v][i], v);
  }
  return dp[v];
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    roads[a].push_back(b);
    roads[b].push_back(a);
    whites[a] = whites[a] || c == 2;
    whites[b] = whites[b] || c == 2;
  }

  calc(1, -1);

  vector<int> out;
  for (int i = 0; i < 100005; i++) {
    if (dp[i] == 1) {
      out.push_back(i);
    }
  }

  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i]);
  }
}
