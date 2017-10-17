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

struct element {
  int row;
  int col;
  char dir;
  int num_turns;

  element(int row, int col, char dir, int num_turns) {
    this->row = row;
    this->col = col;
    this->dir = dir;
    this->num_turns = num_turns;
  }

  bool operator==(const element& other) const {
    return this->row == other.row &&
           this->col == other.col &&
           this->dir == other.dir &&
           this->num_turns == other.num_turns;
  }

  bool operator<(const element& other) const {
    if (this->row != other.row) {
      return this->row < other.row;
    }
    if (this->col != other.col) {
      return this->col < other.col;
    }
    if (this->dir != other.dir) {
      return this->dir < other.dir;
    }
    if (this->num_turns != other.num_turns) {
      return this->num_turns < other.num_turns;
    }
    return false;
  }
};

pair<int, int> dir_to_diff(char c) {
  if (c == 'N') {
    return {0, 1};
  } else if (c == 'S') {
    return {0, -1};
  } else if (c == 'W') {
    return {-1, 0};
  } else {
    return {1, 0};
  }
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
  }
  int start_r = 0;
  int start_c = 0;
  int end_r = 0;
  int end_c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'S') {
        start_r = i;
        start_c = j;
      }
      if (grid[i][j] == 'T') {
        end_r = i;
        end_c = j;
      }
    }
  }

  const string DIRS = "NSEW";
  stack<element> s;
  set<element> seen;
  for (int i = 0; i < DIRS.size(); i++) {
    element start = element(start_r, start_c, DIRS[i], 0);
    s.push(start);
    seen.insert(start);
  }

  while (!s.empty()) {
    element e = s.top();
    s.pop();
    for (int i = 0; i < DIRS.size(); i++) {
      pair<int, int> diff = dir_to_diff(DIRS[i]);
      int new_r = e.row + diff.first;
      int new_c = e.col + diff.second;
      if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= m || grid[new_r][new_c] == '*') {
        continue;
      }
      element new_element = element(e.row + diff.first, e.col + diff.second, DIRS[i], e.num_turns + (DIRS[i] != e.dir));
      if (new_element.num_turns > 2 || seen.find(new_element) != seen.end()) {
        continue;
      }
      seen.insert(new_element);
      s.push(new_element);
    }
  }
  for (int i = 0; i < DIRS.size(); i++) {
    for (int j = 0; j <= 2; j++) {
      element e = element(end_r, end_c, DIRS[i], j);
      if (seen.find(e) != seen.end()) {
        printf("YES");
        return 0;
      }
    }
  }
  printf("NO");
  return 0;
}
