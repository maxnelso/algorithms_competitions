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

const int MAXN = 105;
const int MAXK = 15;
const int MOD = 100000000;
int calced[MAXN][MAXN][MAXK][MAXK];
long long memo[MAXN][MAXN][MAXK][MAXK];
int n1, n2, k1, k2;

long long solve(int a1, int a2, int b1, int b2) {
  if (b1 > k1 || b2 > k2) {
    return 0;
  }
  if (a1 == 0 && a2 == 0) {
    return 1;
  }
  if (calced[a1][a2][b1][b2]) {
    return memo[a1][a2][b1][b2];
  }
  calced[a1][a2][b1][b2] = 1;
  long long & res = memo[a1][a2][b1][b2];
  if (a1 > 0) {
    res += solve(a1 - 1, a2, b1 + 1, 0) % MOD;
  }
  if (a2 > 0) {
    res += solve(a1, a2 - 1, 0, b2 + 1) % MOD;
  }
  return res % MOD;
}

int main () {
  scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
  long long out = solve(n1, n2, 0, 0);
  cout << out;
}
