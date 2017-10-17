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

void print_grid(const vector<string>& grid) {
  for (int i = 0; i < grid.size(); i++) {
    printf("%s\n", grid[i].c_str());
  }
}

int main () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  int added = 0;
  pair<int, int> start = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.') {
        added++;
        grid[i][j] = 'X';
        start.first = i;
        start.second = j;
      }
    }
  }
  if (start == make_pair(-1, -1)) {
    print_grid(grid);
    return 0;
  }
  queue<pair<int, int>> q;
  set<pair<int, int>> seen;
  seen.insert(start);
  q.push(start);
  added--;
  grid[start.first][start.second] = '.';
  while (!q.empty() && added != k) {
    pair<int, int> node = q.front();
    q.pop();
    const vector<pair<int, int>> DIRS = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for (auto& d : DIRS) {
      pair<int, int> new_node = make_pair(node.first + d.first, node.second + d.second);
      if (seen.find(new_node) != seen.end()) {
        continue;
      }
      int x = new_node.first;
      int y = new_node.second;
      if (x < 0 || x >= n || y < 0 || y >= m) {
        continue;
      }
      seen.insert(new_node);
      if (grid[x][y] == 'X') {
        grid[x][y] = '.';
        added--;
        if (added == k) {
          break;
        }
        q.push(new_node);
      }
    }
  }

  print_grid(grid);
}
