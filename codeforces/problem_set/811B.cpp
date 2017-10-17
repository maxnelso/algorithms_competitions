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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    int c = 0;
    for (int j = l; j <= r; j++) {
      if (p[j - 1] < p[x - 1]) {
        c++;
      }
    }
    printf("%s\n", c == (x - l) ? "Yes" : "No");
  }
}
