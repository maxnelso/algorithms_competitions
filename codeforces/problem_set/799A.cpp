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
  int n, t, k, d;
  scanf("%d %d %d %d", &n, &t, &k, &d);
  if (n <= k) {
    printf("NO");
    return 0;
  }
  int batches_made = 0;
  while (d >= 0) {
    batches_made++;
    d -= t;
  }
  n -= batches_made * k;
  if (n <= 0) {
    printf("NO");
    return 0;
  }
  if (n > k) {
    printf("YES");
    return 0;
  }
  if (d != 0) {
    printf("YES");
    return 0;
  }
  printf("NO");
}
