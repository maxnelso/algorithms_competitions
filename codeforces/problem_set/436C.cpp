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


struct grid {
  vector<vector<char> > grid;
};

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m, c, w;
  scanf("%d %d %d %d", &n, &m, &c, &w);
  vector<grid> grids;
  for (int i = 0; i < c; i++) {
    grid g;
    for (int j = 0; j < n; j++) {
      g.grid.push_back(vector<char>());
      for (int k = 0; k < m; k++) {
        char c;
        scanf("%c", &c);
        if (c == '\n') {
          k--;
        } else {
          g.grid[i][j] = c;
        }
      }
    }
    grids.push_back(g);
  }
}
