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

int main () {
  vector<string> grid;
  for (int i = 0; i < 8; i++) {
    char c[256];
    scanf("%s", c);
    string s(c);
    grid.push_back(s);
  }
  int rows = 0;
  int cols = 0;
  for (int i = 0; i < 8; i++) {
    bool found_row = true;
    bool found_col = true;
    for (int j = 0; j < 8; j++) {
      found_row = found_row && grid[i][j] == 'B';
      found_col = found_col && grid[j][i] == 'B';
    }
    rows += found_row;
    cols += found_col;
  }

  if (rows + cols == 16) {
    printf("8");
  } else {
    printf("%d", rows + cols);
  }


}
