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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    char c[256];
    scanf("%s", c);
    string s(c);
    grid.push_back(s);
  }
  set<pair<int, int>> goods;
  set<pair<int, int>> bads;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'o') {
        for (int dx = -n; dx <= n; dx++) {
          for (int dy = -n; dy <= n; dy++) {
            if (i + dx < n &&
                i + dx >= 0 &&
                j + dy < n &&
                j + dy >= 0) {
              if (grid[i + dx][j + dy] == 'x' ||
                  grid[i + dx][j + dy] == 'o') {
                goods.insert(make_pair(dx, dy));
              } else {
                bads.insert(make_pair(dx, dy));
              }
            }
          }
        }
      }
    }
  }
  vector<pair<int, int>> result;
  set_difference(goods.begin(), goods.end(), bads.begin(), bads.end(), inserter(result, result.end()));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'x') {
        bool found = false;
        for (int k = 0; k < result.size(); k++) {
          int dx = result[k].first;
          int dy = result[k].second;
          if (i - dx < n &&
              i - dx >= 0 &&
              j - dy < n &&
              j - dy >= 0) {
            if (grid[i - dx][j - dy] == 'o') {
              found = true;
              break;
            }
          }
        }
        if (!found) {
          printf("NO");
          return 0;
        }
      }
    }
  }
  vector<string> out;
  for (int i = 0; i < 2*n - 1; i++) {
    string row = "";
    for (int j = 0; j < 2*n - 1; j++) {
      row += '.';
    }
    out.push_back(row);
  }
  int start = n - 1;
  for (int i = 0; i < result.size(); i++) {
    out[start + result[i].first][start + result[i].second] = 'x';
  }
  out[start][start] = 'o';
  printf("YES\n");
  for (int i = 0; i < out.size(); i++) {
    printf("%s\n", out[i].c_str());
  }
}

