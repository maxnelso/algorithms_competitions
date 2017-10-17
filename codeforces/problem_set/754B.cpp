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

bool winning(vector<vector<char>> grid) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // Horizontal
      if (j + 2 < 4 && grid[i][j] == 'x' && grid[i][j + 1] == 'x' && grid[i][j + 2] == 'x') {
        return true;
      }
      // Vertical
      if (i + 2 < 4 && grid[i][j] == 'x' && grid[i + 1][j] == 'x' && grid[i + 2][j] == 'x') {
        return true;
      }
      // Diagonal right
      if (i + 2 < 4 && j + 2 < 4 && grid[i][j] == 'x' && grid[i + 1][j + 1] == 'x' && grid[i + 2][j + 2] == 'x') {
        return true;
      }
      if (i + 2 < 4 && j - 2 >= 0 && grid[i][j] == 'x' && grid[i + 1][j - 1] == 'x' && grid[i + 2][j - 2] == 'x') {
        return true;
      }
    }
  }
  return false;
}

int main () {
  vector<vector<char>> grid;
  for (int i = 0; i < 4; i++) {
    vector<char> row;
    for (int j = 0; j < 4; j++) {
      char c;
      scanf("%c", &c);
      row.push_back(c);
    }
    scanf("\n");
    grid.push_back(row);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (grid[i][j] == '.') {
        grid[i][j] = 'x';
        if (winning(grid)) {
          printf("YES");
          return 0;
        }
        grid[i][j] = '.';
      }
    }
  }
  printf("NO");
  return 0;
}
