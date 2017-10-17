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

char grid[51][51];
int n, m;
bool visited[51][51];
bool found = false;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int last_x, int last_y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[x][y] != grid[new_x][new_y]) {
      continue;
    }
    if (visited[new_x][new_y] && new_x != last_x && new_y != last_y) {
      found = true;
    }
    if (!visited[new_x][new_y]) {
      dfs(new_x, new_y, x, y);
    }
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", &grid[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(i, j, -1, -1);
      }
    }
  }
  if (found) {
    printf("Yes");
  } else {
    printf("No");
  }

}
