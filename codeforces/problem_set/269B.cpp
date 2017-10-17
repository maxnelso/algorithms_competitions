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

const int MAXN = 5005;
int dp[MAXN];

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> species;
  for (int i = 0; i < n; i++) {
    int a;
    float useless;
    scanf("%d %f", &a, &useless);
    species.push_back(a);
  }

  for (int i = 0; i < species.size(); i++) {
    int s = species[i];
    for (int j = s; j >= 0; j--) {
      dp[s] = max(dp[s], 1 + dp[j]);
    }
  }

  int out = 0;
  for (int i = 0; i < MAXN; i++) {
    out = max(out, dp[i]);
  }
  printf("%d", n - out);
}
