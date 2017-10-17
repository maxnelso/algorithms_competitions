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

int a[18][1 << 17];

int main () {
  // segment tree
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < 1 << n; i++) {
    scanf("%d", &a[0][i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << (n - i)); j += 2) {
      if (i % 2 == 0) {
        a[i + 1][j / 2] = a[i][j] | a[i][j + 1];
      } else {
        a[i + 1][j / 2] = a[i][j] ^ a[i][j + 1];
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    a[0][x] = y;

    for (int j = 0; j < n; j++) {
      if (j % 2 == 0) {
        if (x % 2 == 0) {
          a[j + 1][x / 2] = a[j][x] | a[j][x + 1];
        } else {
          a[j + 1][x / 2] = a[j][x] | a[j][x - 1];
        }
      } else {
        if (x % 2 == 0) {
          a[j + 1][x / 2] = a[j][x] ^ a[j][x + 1];
        } else {
          a[j + 1][x / 2] = a[j][x] ^ a[j][x - 1];
        }
      }
      x /= 2;
    }
    printf("%d\n", a[n][0]);
  }
}
