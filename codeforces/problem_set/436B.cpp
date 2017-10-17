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
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> counts(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      scanf("%c", &c);
      if (c == '\n') {
        j--;
      }
      if (c == 'U' && i != 1) {
        counts[j]++;
      }
      if (c == 'R') {
        for (int k = j; k < m; k++) {
          int time_elapased = k - j;
          if (i == time_elapased) {
            counts[k]++;
          }
        }
      }
      if (c == 'L') {
        for (int k = j; k >= 0; k--) {
          int time_elapased = j - k;
          if (i == time_elapased) {
            counts[k]++;
          }
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d ", counts[i]);
  }
}
