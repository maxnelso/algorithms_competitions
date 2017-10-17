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
#define print_vector(a) for (int i = 0; i < a.size(); i++) { if (i == a.size() - 1) {cout << a[i];} else { cout << a[i] << " ";}}
using namespace std;

int main () {
  int m, n;
  scanf("%d %d", &m, &n);
  int t = 0;
  vector<vector<int> > memo; // painting x painter
  vector<vector<int> > times;
  for (int i = 0; i < m; ++i) {
    vector<int> u;
    vector<int> v;
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      v.push_back(a);
      u.push_back(0);
    }
    times.push_back(v);
    memo.push_back(u);
  }
  memo[0][0] = times[0][0];
  for (int j = 1; j < m; ++j) {
    memo[j][0] = memo[j-1][0] + times[j][0];
  }
  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      if (i == 0) {
        memo[0][j] = memo[0][j-1] + times[0][j];
      } else {
        memo[i][j] = max(memo[i-1][j], memo[i][j-1]) + times[i][j];
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (i != m - 1) {
      printf("%d ", memo[i][n-1]);
    } else {
      printf("%d", memo[i][n-1]);
    }
  }
  fflush(stdout);
}
