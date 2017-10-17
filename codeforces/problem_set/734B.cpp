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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int k2, k3, k5, k6;
  scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
  int twofiftysixes = min(k2, min(k5, k6));
  int out = twofiftysixes * 256;
  k2 -= twofiftysixes;
  int thirtytwos = min(k2, k3);
  out += thirtytwos * 32;
  printf("%d", out);
}
