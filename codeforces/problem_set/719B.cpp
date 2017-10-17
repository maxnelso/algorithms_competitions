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

int out_arrangement(string cockroaches, bool black) {
  int out = 0;
  int n = cockroaches.size();
  int badrs = 0;
  int badbs = 0;
  for (int i = 0; i < n; i++) {
    if (black && cockroaches[i] != 'b') {
      badrs++;
    } else if (!black && cockroaches[i] != 'r') {
      badbs++;
    }
    black = !black;
  }
  out = min(badrs, badbs) + max(badbs, badrs) - min(badbs, badrs);
  return out;
}

int main () {
  int n;
  scanf("%d", &n);
  char c[100005];
  scanf("%s", c);
  string cockroaches(c);
  int rs = 0;
  printf("%d", min(out_arrangement(cockroaches, true), out_arrangement(cockroaches, false)));
}
