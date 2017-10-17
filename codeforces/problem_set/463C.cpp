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

const int MAXN = 2020;
int a[MAXN][MAXN];

long long diagonal1[2 * MAXN];
long long diagonal2[2 * MAXN];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      diagonal1[i + j] += a[i][j];
      diagonal2[i - j + n] += a[i][j];
    }
  }

  vector<long long> best_pair = {-1, -1};
  pair<int, int> best_cells[2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int parity = (i + j) % 2;
      long long value = diagonal1[i + j] + diagonal2[i - j + n] - a[i][j];
      if (value > best_pair[parity]) {
        best_pair[parity] = value;
        best_cells[parity] = {i, j};
      }
    }
  }

  cout << best_pair[0] + best_pair[1] << endl;
  cout << best_cells[0].first << " " << best_cells[0].second << " " << best_cells[1].first << " " << best_cells[1].second;
}
