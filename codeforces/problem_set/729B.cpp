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
  vector<vector<int>> grid;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      row.push_back(a);
    }
    grid.push_back(row);
  }

  int out = 0;
  // Left's / Right's
  for (int i = 0; i < n; i++) {
    int first_one = -1;
    int last_one = -1;
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1 && first_one == -1) {
        first_one = j;
      }
      if (grid[i][j] == 1) {
        last_one = j;
      }
    }
    if (first_one == -1 || last_one == -1) {
      continue;
    }
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        continue;
      }
      if (j < first_one) {
        out++;
      }
      if (j > first_one && j < last_one) {
        out += 2;
      }
      if (j > last_one) {
        out++;
      }
    }
  }

  // Tops' / bottoms
  for (int j = 0; j < m; j++) {
    int first_one = -1;
    int last_one = -1;
    for (int i = 0; i < n; i++) {
      if (grid[i][j] == 1 && first_one == -1) {
        first_one = i;
      }
      if (grid[i][j] == 1) {
        last_one = i;
      }
    }
    if (first_one == -1 || last_one == -1) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (grid[i][j] == 1) {
        continue;
      }
      if (i < first_one) {
        out++;
      }
      if (i > first_one && i < last_one) {
        out += 2;
      }
      if (i > last_one) {
        out++;
      }
    }
  }
  printf("%d", out);
}
