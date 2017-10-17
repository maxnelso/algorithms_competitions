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

const int MAXN = 500;
int a[MAXN][MAXN];
int b[MAXN];
int c[MAXN];
long long d[MAXN];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }

  for (int i = n - 1; i >= 0; i--) {
    long long sum = 0;

    c[b[i]] = 1;

    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        a[j][k] = min(a[j][k], a[j][b[i]] + a[b[i]][k]);
        if (c[j] == 1 && c[k] == 1) {
          sum += a[j][k];
        }
      }
    }
    d[i] = sum;
  }
  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }
}
