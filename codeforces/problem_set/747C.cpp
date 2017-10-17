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
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> servers(n);
  int prev_t = 0;
  for (int i = 0; i < q; i++) {
    int t, k, d;
    scanf("%d %d %d", &t, &k, &d);
    int c = 0;
    for (int j = 0; j < n; j++) {
      servers[j] = max(0, servers[j] - (t - prev_t));
      c += servers[j] == 0;
    }
    prev_t = t;
    if (c < k) {
      printf("-1\n");
      continue;
    }
    c = 0;
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (servers[j] == 0) {
        servers[j] = d;
        c++;
        sum += j + 1;
      }
      if (c == k) {
        break;
      }
    }
    printf("%d\n", sum);
  }
}
