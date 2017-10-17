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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = m; i <= n; i += m) {
    for (int j = 0; j <= i; j++) {
      int k = i - j;
      if (j + 2 * k == n) {
        printf("%d", i);
        exit(0);
      }
    }
  }
  printf("-1");
}
