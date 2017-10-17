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

vector<string> grid;
int n, m;
int end_x, end_y;

struct path {
  pair<int, int> current;
  vector<char> p;
};

bool handle_one() {
  if (n == 1) {
    printf("R\n");
    fflush(stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      while (grid[a - 1][b - 1] != 'F') {
        printf("L\n");
        fflush(stdout);
        scanf("%d %d", &a, &b);
      }
      return true;
    } else {
      while (grid[a - 1][b - 1] != 'F') {
        printf("R\n");
        fflush(stdout);
        scanf("%d %d", &a, &b);
      }
      return true;
    }
  } else if (m == 1) {
    printf("D\n");
    fflush(stdout);
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      while (grid[a - 1][b - 1] != 'F') {
        printf("U\n");
        fflush(stdout);
        scanf("%d %d", &a, &b);
      }
      return true;
    } else {
      while (grid[a - 1][b - 1] != 'F') {
        printf("D\n");
        fflush(stdout);
        scanf("%d %d", &a, &b);
      }
      return true;
    }
  }
  return false;
}

path get_path(int x, int y) {
  queue<path> q;
  path start;
  start.p = vector<char>();
  start.current = make_pair(x, y);
  q.push(start);
  set<pair<int, int>> seen;
  const vector<pair<int, int>> MOVES = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  const vector<char> MOVES_C = { 'D', 'U', 'R', 'L' };
  while (!q.empty()) {
    path pa = q.front();
    pair<int, int> p = pa.current;
    q.pop();
    for (int i = 0; i < MOVES.size(); i++) {
      pair<int, int> new_p = make_pair(p.first + MOVES[i].first, p.second + MOVES[i].second);
      if (seen.find(new_p) != seen.end()) {
        continue;
      }
      if (new_p.first < 0 || new_p.first >= n || new_p.second < 0 || new_p.second >= m) {
        continue;
      }
      if (grid[new_p.first][new_p.second] == '*') {
        continue;
      }
      path new_path;
      new_path.current = new_p;
      new_path.p = pa.p;
      new_path.p.push_back(MOVES_C[i]);
      if (new_p.first == end_x && new_p.second == end_y) {
        return new_path;
      }
      seen.insert(new_p);
      q.push(new_path);
    }
  }
}

int main () {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'F') {
        end_x = i;
        end_y = j;
      }
    }
  }
  if (handle_one()) {
    return 0;
  }

  bool lr_swapped = false;
  bool ud_swapped = false;
  int a, b;

  if (grid[0][1] == 'F') {
    printf("R\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
    printf("L\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    return 0;
  }
  if (grid[1][0] == 'F') {
    printf("D\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
    printf("U\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    return 0;
  }

  if (grid[0][1] == '*') {
    printf("D\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      ud_swapped = true;
    } else {
      ud_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
    while (grid[a - 1][b - 1 + 1] == '*') {
      if (ud_swapped) {
        printf("U\n");
        fflush(stdout);
      } else {
        printf("D\n");
        fflush(stdout);
      }
      scanf("%d %d", &a, &b);
      if (grid[a - 1][b - 1] == 'F') {
        return 0;
      }
    }
    int old_a = a;
    int old_b = b;
    printf("R\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == old_a && b == old_b) {
      lr_swapped = true;
    } else {
      lr_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
  } else if (grid[1][0] == '*') {
    printf("R\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      lr_swapped = true;
    } else {
      lr_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
    while (grid[a - 1 + 1][b - 1] == '*') {
      if (lr_swapped) {
        printf("L\n");
        fflush(stdout);
      } else {
        printf("R\n");
        fflush(stdout);
      }
      scanf("%d %d", &a, &b);
      if (grid[a - 1][b - 1] == 'F') {
        return 0;
      }
    }
    int old_a = a;
    int old_b = b;
    printf("D\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == old_a && b == old_b) {
      ud_swapped = true;
    } else {
      ud_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }
  } else {
    printf("R\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      lr_swapped = true;
    } else {
      lr_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }

    printf("%c\n", lr_swapped ? 'R' : 'L');
    fflush(stdout);
    scanf("%d %d", &a, &b);
    printf("D\n");
    fflush(stdout);
    scanf("%d %d", &a, &b);
    if (a == 1 && b == 1) {
      ud_swapped = true;
    } else {
      ud_swapped = false;
    }
    if (grid[a - 1][b - 1] == 'F') {
      return 0;
    }

  }
  path p = get_path(a - 1, b - 1);
  for (int i = 0; i < p.p.size(); i++) {
    if (p.p[i] == 'D') {
      printf("%c\n", ud_swapped ? 'U' : 'D');
    } else if (p.p[i] == 'U') {
      printf("%c\n", ud_swapped ? 'D' : 'U');
    } else if (p.p[i] == 'L') {
      printf("%c\n", lr_swapped ? 'R' : 'L');
    } else if (p.p[i] == 'R') {
      printf("%c\n", lr_swapped ? 'L' : 'R');
    }
    fflush(stdout);
    scanf("%d %d", &a, &b);
  }
  return 0;
}
