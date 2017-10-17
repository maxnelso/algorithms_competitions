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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int get_adjacent(vector<vector<char>> grid, int x, int y) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  int count = 0;
  for (int i = 0; i < 4; ++i) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (new_x >= 0 && new_x < grid[0].size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == 'o') {
      count++;
    }
  }
  return count;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  vector<vector<char>> grid;
  for (int i = 0; i < n; ++i) {
    scanf("\n");
    vector<char> row;
    for (int j = 0; j < n; ++j) {
      char a;
      scanf("%c", &a);
      row.push_back(a);
    }
    grid.push_back(row);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (get_adjacent(grid, i, j) % 2 != 0) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
  return 0;
}
