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

int main () {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  vector<vector<int>> grid;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      row.push_back(a);
      nums.push_back(a);
    }
    grid.push_back(row);
  }
  sort(nums.begin(), nums.end());
  int out = 0;
  int start = nums[nums.size() / 2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((grid[i][j] - start) % d == 0) {
        out += abs((grid[i][j] - start) / d);
      } else {
        printf("-1");
        return 0;
      }
    }
  }

  printf("%d", out);
}
