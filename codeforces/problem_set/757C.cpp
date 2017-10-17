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
  int n, m;
  scanf("%d %d", &n, &m);
  const int N = 1e6;
  const long long MOD = 1e9 + 7;
  long long fact[N];
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  vector<vector<int>> x(m);
  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    for (int j = 0; j < s; j++) {
      int t;
      scanf("%d", &t);
      x[t-1].push_back(i);
    }
  }
  for (int i = 0; i < m; i++) {
    sort(x[i].begin(), x[i].end());
  }
  sort(x.begin(), x.end());
  long long ans = 1;
  long long sm = 1;
  for (int i = 1; i < m; i++) {
    if (x[i] == x[i -1]) {
      sm++;
    } else {
      ans = (ans * (fact[sm])) % MOD;
      sm = 1;
    }
  }
  ans = (ans * (fact[sm])) % MOD;
  cout << ans;

}
