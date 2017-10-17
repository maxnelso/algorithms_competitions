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
  int n;
  scanf("%d", &n);
  char c[1010];
  scanf("%s", c);
  string s(c);
  string tmp;
  string best;
  for (int i = 0; i < n; i++) {
    best += "9";
    tmp += "9";
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[(i + j) % n] = s[j];
    }
    int diff = '0' - tmp[0];
    for (int j = 0; j < n; j++) {
      tmp[j] = tmp[j] + diff;
      if (tmp[j] < '0') {
        tmp[j] += 10;
      }
    }
    if (tmp < best) {
      best = tmp;
    }
  }
  printf("%s", best.c_str());
}
