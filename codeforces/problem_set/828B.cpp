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
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  pair<int, int> xs = {105, -1};
  pair<int, int> ys = {105, -1};
  bool found = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'B') {
        found = true;
        xs.first = min(xs.first, i);
        xs.second = max(xs.second, i);
        ys.first = min(ys.first, j);
        ys.second = max(ys.second, j);
      }
    }
  }

  if (!found) {
    printf("1");
    return 0;
  }

  int x_diff = xs.second - xs.first;
  int y_diff = ys.second - ys.first;
  int count_in_square = 0;
  for (int i = xs.first; i <= xs.second; i++) {
    for (int j = ys.first; j <= ys.second; j++) {
      if (grid[i][j] == 'W') {
        count_in_square++;
      }
    }
  }
  if (x_diff == y_diff) {
    printf("%d", count_in_square);
    return 0;
  }
  if (x_diff > y_diff) {
    int need = x_diff - y_diff;
    int on_left = ys.first;
    int on_right = m - ys.second - 1;
    if (on_left + on_right < need) {
      printf("-1");
      return 0;
    }
    printf("%d", count_in_square + (need * (xs.second - xs.first + 1)));
  } else {
    int need = y_diff - x_diff;
    int on_top = xs.first;
    int on_bottom = n - xs.second - 1;
    if (on_top + on_bottom < need) {
      printf("-1");
      return 0;
    }
    printf("%d", count_in_square + (need * (ys.second - ys.first + 1)));
  }
  return 0;
}
