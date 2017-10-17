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

const int MAXN = 3005;
int dp[MAXN][2];
vector<int> a;
vector<int> b;
vector<int> c;
int n;

int solve(int position, bool state) {
  if (position == n - 1) {
    if (state) {
      return b[position];
    }
    return a[position];
  }

  if (dp[position][state] != -1) {
    return dp[position][state];
  }

  int out = 0;
  if (state) {
    out = max(solve(position + 1, true) + b[position], solve(position + 1, false) + c[position]);
  } else {
    out = max(solve(position + 1, true) + a[position], solve(position + 1, false) + b[position]);
  }

  dp[position][state] = out;
  return out;
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    b.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    c.push_back(x);
  }

  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = -1;
    }
  }

  printf("%d", solve(0, false));

}
