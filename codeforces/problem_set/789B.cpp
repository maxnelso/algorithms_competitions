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
  long long b, q, l, m;
  cin >> b >> q >> l >> m;
  set<long long> bads;
  for (int i = 0; i < m; i++) {
    long long a;
    cin >> a;
    bads.insert(a);
  }
  if (q == 0) {
    if (l < abs(b)) {
      printf("0");
      return 0;
    }
    if (bads.find(0) == bads.end()) {
      printf("inf");
      return 0;
    }
    if (bads.find(b) == bads.end()) {
      printf("1");
    } else {
      printf("0");
    }
    return 0;
  }
  set<long long> seen;
  while (abs(b) <= l) {
    if (seen.find(b) != seen.end()) {
      for (auto a: seen) {
        if (bads.find(a) == bads.end()) {
          printf("inf");
          return 0;
        }
      }
      printf("0");
      return 0;
    }
    seen.insert(b);
    b *= q;
  }
  int out = 0;
  for (auto a: seen) {
    if (bads.find(a) == bads.end()) {
      out++;
    }
  }
  printf("%d", out);
  return 0;
}
