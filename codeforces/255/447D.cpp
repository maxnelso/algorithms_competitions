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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m, k, p;
  scanf("%d %d %d %d", &n, &m, &k, &p);
  vector<vector<int>> matrix;
  priority_queue<int> row_sums;
  vector<int> cols;
  for (int i = 0; i < m; i++) {
    cols.push_back(0);
  }
  for (int i = 0; i < n; i++) {
    vector<int> row;
    int sum = 0;
    for (int j = 0; j < m; j++) {
      int a;
      scanf("%d", &a);
      sum += a;
      row.push_back(a);
      cols[j] += a;
    }
    row_sums.push(sum);
    matrix.push_back(row);
  }
  priority_queue<int> col_sums;
  for (int i = 0; i < cols.size(); i++) {
    col_sums.push(cols[i]);
  }
  int row_ds = 0;
  int col_ds = 0;
  int result = 0;
  for (int z = 0; z < k; z++) {
    if (row_sums.top() - (row_ds * p) > col_sums.top() - (col_ds * p)) {
      int max = row_sums.top() - (row_ds * p);
      col_ds++;
      row_sums.pop();
      row_sums.push(max - (m * p));
      result += max;
    } else {
      int max = col_sums.top() - (col_ds * p);
      row_ds++;
      col_sums.pop();
      col_sums.push(max - (n * p));
      result += max;
    }
  }
  printf("%d", result);
}
