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
  int n;
  scanf("%d", &n);
  vector<int> stewards;
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    m[a]++;
  }
  if (m.size() == 1) {
    printf("%d", 0);
    return 0;
  }
  int out = 0;
  for (auto it = next(m.begin()); it != prev(m.end()); it++) {
    out += it->second;
  }
  printf("%d", out);
}
