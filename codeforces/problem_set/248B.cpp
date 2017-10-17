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
  int n;
  scanf("%d", &n);
  double best = -1;
  for (double i = pow(10, n-1); i <= pow(10, n); ++i) {
    if (i % 2 == 0 &&
        i % 3 == 0 &&
        i % 5 == 0 &&
        i % 7 == 0) {
      best = i;
      break;
    }
  }
  printf("%d", best);
  setvbuf(stdout, NULL, _IONBF, 0);
}
