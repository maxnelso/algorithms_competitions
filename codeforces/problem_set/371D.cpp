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

int vessels[200000];
int current[200000];
int main () {
  int n;
  scanf("%d", &n);
  vector<int> vessels(n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &vessels[i]);
  }
  int m;
  scanf("%d", &m);
  set<int> next_to_be_filled;
  for (int i = 0; i < n; i++) {
    next_to_be_filled.insert(i);
  }

  for (int i = 0; i < m; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x, p;
      scanf("%d %d", &p, &x);
      p--;
      while (x > 0) {
        auto it = next_to_be_filled.lower_bound(p);
        if (it == next_to_be_filled.end()) {
          break;
        }
        auto index = (*it);
        int t = min(x, vessels[index] - current[index]);
        current[index] += t;
        x -= t;
        if (vessels[index] - current[index] == 0) {
          next_to_be_filled.erase(index);
        }
      }
    } else {
      int a;
      scanf("%d", &a);
      a--;
      printf("%d\n", current[a]);
    }
  }
}
