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
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  int max_count = 0;
  for (int as = 0; as <= n; as++) {
    for (int bs = 0; bs <= n; bs++) {
      int left = n - (as * a + bs * b);
      if (left < 0 || left % c != 0) {
        continue;
      }
      int cs = left / c;
      max_count = max(max_count, as + bs + cs);
    }
  }
  printf("%d", max_count);
}
