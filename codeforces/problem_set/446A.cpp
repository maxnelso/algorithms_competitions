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

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  int l[100002];
  int r[100002];
  int a[100004];
  for (int i = 1; i <= n; i++) {
    int z;
    scanf("%d", &z);
    a[i] = z;
  }
  int other_max = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i-1]) {
      l[i] = l[i-1] + 1;
    } else {
      l[i] = 1;
    }
    other_max = max(other_max, l[i]);
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] < a[i+1]) {
      r[i] = r[i+1] + 1;
    } else {
      r[i] = 1;
    }
    other_max = max(other_max, l[i]);
  }
  if (other_max != n) {
    other_max++;
  }
  int out = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i-1] + 1 < a[i+1]) {
      out = max(out, l[i-1] + 1 + r[i+1]);
    }
  }
  printf("%d", max(other_max, out));
}
