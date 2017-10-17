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
  char president;
  scanf("%d %d %c", &n, &m, &president);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    char c[256];
    scanf("%s", c);
    string s(c);
    grid.push_back(s);
  }
  set<char> added;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != president) {
        continue;
      }
      // Top
      if (i - 1 >= 0 && grid[i-1][j] != '.' && grid[i-1][j] != president) {
        added.insert(grid[i-1][j]);
      }
      // Bottom
      if (i + 1 < n && grid[i+1][j] != '.' && grid[i+1][j] != president) {
        added.insert(grid[i+1][j]);
      }
      // Left
      if (j - 1 >= 0 && grid[i][j-1] != '.' && grid[i][j-1] != president) {
        added.insert(grid[i][j-1]);
      }
      // Right
      if (j + 1 < m && grid[i][j+1] != '.' && grid[i][j+1] != president) {
        added.insert(grid[i][j+1]);
      }
    }
  }
  printf("%d", added.size());
}
