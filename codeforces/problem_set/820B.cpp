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

int main () {
  int n, a;
  scanf("%d %d", &n, &a);
  long double interior_angle = ((n - 2) * 180) / n;
  long double step = interior_angle / (n - 2);
  long double min_angle = 100000000000;
  if (n == 3) {
    printf("1 2 3");
    return 0;
  }
  int min_step = -1;
  for (int i = 1; i <= n - 2; i++) {
    if ((long double) fabs(a - i * step) < min_angle) {
      min_angle = min(min_angle, (long double) fabs(a - i * step));
      min_step = i + 2;
    }
  }
  printf("2 1 %d", min_step);
}
