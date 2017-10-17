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

int grid[1011][1011];

bool in_bounds(int n, int m, int x, int y) {
  return y <= m || y >= 1 || x <= n || x >= 1;
}

bool check_rect(int x1, int y1,
                int x2, int y2,
                int x3, int y3,
                int x4, int y4,
                int n, int m) {
  return (in_bounds(n, m, x1, y1) &&
          in_bounds(n, m, x2, y2) &&
          in_bounds(n, m, x3, y3) &&
          in_bounds(n, m, x4, y4) &&
          grid[x1][y1] && grid[x2][y2] && grid[x3][y3] && grid[x4][y4]);
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    grid[a][b] = 1;
    if (check_rect(a - 1, b - 1,
                   a, b - 1,
                   a - 1, b,
                   a, b,
                   n, m) ||
        check_rect(a, b - 1,
                   a + 1, b - 1,
                   a + 1, b,
                   a, b,
                   n, m) ||
        check_rect(a, b,
                   a + 1, b,
                   a + 1, b + 1,
                   a, b + 1,
                   n, m) ||
        check_rect(a - 1, b,
                   a, b,
                   a, b + 1,
                   a - 1, b + 1,
                   n, m)) {
      printf("%d", i + 1);
      return 0;
    }
  }
  printf("0");
}
