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

const int MAX_N = 103;

int dp[MAX_N][MAX_N];

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int a;
    scanf("%d", &a);
    dp[i][i+1] = a;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 2; j <= n; j++) {
      dp[i][j] = dp[i][j-1] + dp[j-1][j];
    }
  }
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d", dp[a][b]);
}
