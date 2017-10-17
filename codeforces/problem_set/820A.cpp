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
  int c, v0, v1, a, l;
  scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);

  int t = 0;
  int start_c = c;
  while (true) {
    c -= v0;
    t++;
    if (c <= 0) {
      printf("%d", t);
      return 0;
    }
    v0 = min(v0 + a, v1);
    c = min(start_c, c + l);
  }
}
