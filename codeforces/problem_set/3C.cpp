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

int get_win_count(string grid[], char c) {
  int count = 0;
  for (int i = 0; i < 3; i++) { // Verticals
    bool found = true;
    for (int j = 0; j < 3; j++) {
      found &= grid[j][i] == c;
    }
    count += found;
  }
  for (int i = 0; i < 3; i++) { // Horizontals
    bool found = true;
    for (int j = 0; j < 3; j++) {
      found &= grid[i][j] == c;
    }
    count += found;
  }
  bool found = true;
  for (int i = 0; i < 3; i++) { // Diagonals
    found &= grid[i][i] == c;
  }
  count += found;
  found = true;
  for (int i = 0; i < 3; i++) { // Diagonals
    found &= grid[2 - i][i] == c;
  }
  count += found;
  return count;
}

int get_count(string grid[], char c) {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      count += grid[i][j] == c;
    }
  }
  return count;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  string grid[3];
  for (int i = 0; i < 3; i++) {
    char c[5];
    scanf("%s", c);
    grid[i] = string(c);
  }
  int x_count = get_count(grid, 'X');
  int o_count = get_count(grid, '0');
  int x_wins = get_win_count(grid, 'X');
  int o_wins = get_win_count(grid, '0');
  if (abs(x_count - o_count) > 1) {
    printf("illegal");
  } else if (x_wins && o_wins) {
    printf("illegal");
  } else if (o_count > x_count) {
    printf("illegal");
  } else if (o_wins && x_count > o_count) {
    printf("illegal");
  } else if (x_wins && x_count <= o_count) {
    printf("illegal");
  } else if (x_wins) {
    printf("the first player won");
  } else if (o_wins) {
    printf("the second player won");
  } else if (x_count + o_count == 9) {
    printf("draw");
  } else if (x_count > o_count) {
    printf("second");
  } else {
    printf("first");
  }

}
