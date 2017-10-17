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

const int MAXN = (int) 400000;
int a[MAXN];

int main () {
  int n;
  scanf("%d", &n);
  int end = 1;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int k, x;
      scanf("%d %d", &k, &x);
      s += x * k * 1LL;
      a[k] += x;
    } else if (type == 2) {
      int x;
      scanf("%d", &x);
      a[end] -= x;
      end++;
      a[end] += x;
      s += x;
    } else {
      a[end - 1] += a[end];
      s -= a[end];
      a[end] = 0;
      end--;
    }
    printf("%.10f\n", 1.0 * s / end);
  }
}
