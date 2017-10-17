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

const int MAXN = 1005;
int ans[MAXN][MAXN];

int main () {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);

  if (d * log(k) + .00000001 < log(n)) {
    printf("-1");
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = ans[i - 1][j];
    }

    for (int j = d - 1; j >= 0; j--) {
      ans[i][j] = (ans[i][j] + 1) % k;
      if (ans[i][j]) {
        break;
      }
    }
  }

  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ans[j][i] + 1);
    }
    printf("\n");
  }
}
