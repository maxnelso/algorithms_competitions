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

char s[5100][5100];
int cycle[10000], cn;
int color[5100], cc, num[5100];

vector<vector<int>> edges;
int n;

void print(int l, int r) {
  if (r - l == 2) {
    for (int i = l; i <= r; ++i)
      printf("%d ", cycle[i] + 1);
    exit(0);
  }
  int u = cycle[l];
  int v = cycle[l + 2];
  if (s[v][u] == '1')
    print(l, l + 2);
  else {
    cycle[r + 1] = cycle[l];
    print(l + 2, r + 1);
  }
}


void dfs(int node) {
  color[node] = cc;
  cycle[++cn] = node;
  num[node] = cn;

  for (int i = 0; i < n; i++) {
    if (s[node][i] != '1') {
      continue;
    }
    if (color[i] == cc) {
      print(num[i], cn);
    } else if (!color[i]) {
      dfs(i);
    }
  }
  color[node] = -1;
  --cn;
}

int main () {
  scanf("%d", &n);
  edges.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s\n", s[i]);
  }

  for (int i = 0; i < n; i++) {
    if (!color[i]) {
      cc++;
      dfs(i);
    }
  }

  printf("-1");
}
