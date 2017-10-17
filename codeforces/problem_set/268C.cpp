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
  int n, m;
  scanf("%d %d", &n, &m);

  int out = min(n, m) + 1;

  printf("%d\n", out);
  for (int i = 0; i < out; i++) {
    if (n > m) {
      printf("%d %d\n", max(n, m) - i, i);
    } else {
      printf("%d %d\n", i, max(n, m) - i);
    }
  }
}
