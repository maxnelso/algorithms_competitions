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
  int l, r, x, y, k;
  scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
  for (int i = l; i <= r; i++) {
    if (i % k == 0 && (i / k >= x && i / k <= y)) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
