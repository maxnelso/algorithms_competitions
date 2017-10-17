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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

bool seen[3000][3000];

struct rect {
  int x_min, x_max, y_min, y_max;
};

vector<pair<int, int>> get_neighbors(int x, int y, int n, int m) {
  vector<pair<int, int>> out;
  if (x + 1 <= m - 1) {
    out.push_back(make_pair(x + 1, y));
  }
  if (x - 1 >= 0) {
    out.push_back(make_pair(x - 1, y));
  }
  if (y + 1 <= n - 1) {
    out.push_back(make_pair(x, y + 1));
  }
  if (y - 1 >= 0) {
    out.push_back(make_pair(x, y - 1));
  }
  return out;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    char c[3000];
    scanf("%s", c);
    string s(c);
    grid.push_back(s);
  }
  bool found = true;
  while (found) {
    vector<rect> rects;
    found = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!seen[j][i] && grid[i][j] == '.') {
          int x_min = j, x_max = j;
          int y_min = i, y_max = i;
          queue<pair<int, int>> q;
          q.push(make_pair(j, i));
          seen[j][i] = true;
          while (!q.empty()) {
            pair<int, int> coords = q.front();
            q.pop();

            // Update
            x_min = min(x_min, coords.first);
            x_max = max(x_max, coords.first);
            y_min = min(y_min, coords.second);
            y_max = max(y_max, coords.second);

            // Add neighbors
            vector<pair<int, int>> neighbors = get_neighbors(coords.first, coords.second, n, m);
            for (int k = 0; k < neighbors.size(); k++) {
              if (grid[neighbors[k].second][neighbors[k].first] == '.' && !seen[neighbors[k].first][neighbors[k].second]) {
                seen[neighbors[k].first][neighbors[k].second] = true;
                q.push(neighbors[k]);
              }
            }
          }
          rect r;
          r.x_min = x_min;
          r.x_max = x_max;
          r.y_min = y_min;
          r.y_max = y_max;
          rects.push_back(r);
        }
      }
    }
    for (int i = 0; i < rects.size(); i++) {
      for (int x = rects[i].x_min; x <= rects[i].x_max; x++) {
        for (int y = rects[i].y_min; y <= rects[i].y_max; y++) {
          if (grid[y][x] == '*') {
            found = true;
          }
          grid[y][x] = '.';
          seen[x][y] = false;
        }
      }
    }
  }
  for (int i = 0; i < grid.size(); i++) {
    printf("%s\n", grid[i].c_str());
  }
}
