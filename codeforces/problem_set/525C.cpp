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
  vector<int> sticks;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sticks.push_back(a);
  }
  sort(sticks.begin(), sticks.end());
  long long out = 0;
  for (int i = sticks.size() - 1; i >= 3; i--) {
    long long a, b, c, d;
    a = sticks[i];
    b = sticks[i-1];
    c = sticks[i-2];
    d = sticks[i-3];
    if (abs(a - b) > 1 || abs(c - d) > 1) {
      continue;
    }
    if (abs(a - b) == 1) {
      a--;
    }
    if (abs(c - d) == 1) {
      c--;
    }
    out += a * c;
    i -= 3;
  }
  cout << out;
}
