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

int hamming_distance(int x, int y) {
  int out = 0;
  while (x > 0 || y > 0) {
    printf("%d %d\n", x, y);
    out += (x & 1) != (y & 1);
    x = x >> 1;
    y = y >> 1;
  }
  return out;
}

int main () {
  printf("%d", hamming_distance(1, 4));
}
