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

vector<string> grid;
int n, m;

vector<pair<int, int>> get_adjacent(int x, int y) {
  vector<pair<int, int>> out;
  if (x > 0) {
    out.push_back(make_pair(x - 1, y));
  }
  if (x < n - 1) {
    out.push_back(make_pair(x + 1, y));
  }
  if (y > 0) {
    out.push_back(make_pair(x, y - 1));
  }
  if (y < m - 1) {
    out.push_back(make_pair(x, y + 1));
  }
  return out;
}

int main () {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  int r1, c1;
  scanf("%d %d", &r1, &c1);
  r1--;
  c1--;
  int r2, c2;
  scanf("%d %d", &r2, &c2);
  r2--;
  c2--;

  vector<pair<int, int>> adj = get_adjacent(r2, c2);
  int c = 0;
  for (auto& p : adj) {
    if (grid[p.first][p.second] == '.') {
      c++;
    }
  }

  // Check around it, needs two squares if not X
  if (grid[r2][c2] == '.') {
    if (abs(r1 - r2) + abs(c1 - c2) == 1) {
      if (c >= 1) {
        printf("YES");
        return 0;
      }
    }
    if (c < 2) {
      printf("NO");
      return 0;
    }
  }

  if (r1 == r2 && c1 == c2) {
    if (c >= 1) {
      printf("YES");
    } else {
      printf("NO");
    }
    return 0;
  }


  set<pair<int, int>> seen;
  queue<pair<int, int>> q;
  q.push(make_pair(r1, c1));
  seen.insert(make_pair(r1, c1));
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    vector<pair<int, int>> adj = get_adjacent(node.first, node.second);
    for (auto& p : adj) {
      if (seen.find(p) != seen.end()) {
        continue;
      }

      seen.insert(p);

      if (p.first == r2 && p.second == c2) {
        printf("YES");
        return 0;
      }

      if (grid[p.first][p.second] == 'X') {
        continue;
      }

      q.push(p);
    }
  }

  printf("NO");
  return 0;
}
