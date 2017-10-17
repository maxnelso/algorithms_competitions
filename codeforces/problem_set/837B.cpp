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

vector<string> grid;
int n, m;

bool check_horizontal(int start_height, int height) {
  char start = grid[start_height][0];
  for (int i = start_height; i < start_height + height; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != start) {
        return false;
      }
    }
  }
  return true;
}

bool check_vertical(int start_width, int width) {
  char start = grid[0][start_width];
  for (int i = 0; i < n; i++) {
    for (int j = start_width; j < start_width + width; j++) {
      if (grid[i][j] != start) {
        return false;
      }
    }
  }
  return true;
}


int main () {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  bool vertical = false;
  char start = grid[0][0];
  for (int i = 0; i < m; i++) {
    if (grid[0][i] != start) {
      vertical = true;
    }
  }

  if (!vertical) {
    if (n % 3 != 0) {
      printf("NO");
      return 0;
    }
    int height = n / 3;
    if (grid[0][0] == grid[height][0] || grid[height][0] == grid[height * 2][0] || grid[height * 2][0] == grid[0][0]) {
      printf("NO");
      return 0;
    }

    if (!check_horizontal(0, height) || !check_horizontal(height, height) || !check_horizontal(2 * height, height)) {
      printf("NO");
      return 0;
    }
    printf("YES");
    return 0;
  } else {
    if (m % 3 != 0) {
      printf("NO");
      return 0;
    }

    int width = m / 3;
    if (grid[0][0] == grid[0][width] || grid[0][width] == grid[0][2 * width] || grid[0][2 * width] == grid[0][0]) {
      printf("NO");
      return 0;
    }

    if (!check_vertical(0, width) || !check_vertical(width, width) || !check_vertical(2 * width, width)) {
      printf("NO");
      return 0;
    }
    printf("YES");
    return 0;

  }
}
