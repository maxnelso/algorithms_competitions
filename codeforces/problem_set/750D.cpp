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

int n;
int ts[40];
bool seen[400][400];
bool memo[400][400][8][40];

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


using namespace std;

void dfs(int x, int y, int dir, int level) {
  if (memo[x][y][dir][level]) {
    return;
  }

  memo[x][y][dir][level] = true;
  if (level == n) {
    return;
  }

  for (int i = 1; i <= ts[level]; i++) {
    x += dx[dir];
    y += dy[dir];
    seen[x][y] = true;
  }

  dfs(x, y, (dir + 1) % 8, level + 1);
  dfs(x, y, (dir + 7) % 8, level + 1);
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ts[i]);
  }

  dfs(200, 200, 4, 0);
  int out = 0;
  for (int i = 0; i < 400; i++) {
    for (int j = 0; j < 400; j++) {
      out += seen[i][j];
    }
  }

  printf("%d", out);
}
