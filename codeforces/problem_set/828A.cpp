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
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int single_doubles = 0;
  int out = 0;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      if (a == 0) {
        if (b == 0) {
          if (single_doubles == 0) {
            out++;
          } else {
            single_doubles--;
          }
        } else {
          b--;
          single_doubles++;
        }
      } else {
        a--;
      }
    } else {
      if (b == 0) {
        out++;
        out++;
      } else {
        b--;
      }
    }
  }
  printf("%d", out);
}
