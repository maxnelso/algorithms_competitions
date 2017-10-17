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

vector<vector<int>> grid;
int n, k;

void print_grid() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

int main () {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < n; j++) {
      row.push_back(0);
    }
    grid.push_back(row);
  }

  if (k == 0) {
    print_grid();
    return 0;
  }

  if (k > n * n) {
    printf("-1");
    return 0;
  }

  if (k == 2 && k <= n) {
    // Diagonal
    for (int i = 0; i < k; i++) {
      grid[i][i] = 1;
    }
    print_grid();
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        continue;
      }
      if (i == j && k == 2) {
        grid[i][i] = 1;
        grid[i + 1][i + 1] = 1;
        k -= 2;
      } else if (i == j && (k > 2 || k == 1)) {
        grid[i][i] = 1;
        k--;
      } else if (i != j && k >= 2) {
        grid[i][j] = 1;
        grid[j][i] = 1;
        k -= 2;
      }
      if (k == 0) {
        print_grid();
        return 0;
      }
    }
  }
}
