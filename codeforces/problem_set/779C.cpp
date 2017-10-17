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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> as;
  vector<int> bs;
  vector<pair<int, int>> diffs;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    as.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    bs.push_back(b);
  }
  for (int i = 0; i < n; i++) {
    diffs.push_back(make_pair(as[i] - bs[i], i));
  }
  sort(diffs.begin(), diffs.end());
  int out = 0;
  for (int i = 0; i < n; i++) {
    if (i < k) {
      out += as[diffs[i].second]; // Have to buy a
    } else {
      if (diffs[i].first > 0) {
        out += bs[diffs[i].second]; // Want to buy b
      } else {
        out += as[diffs[i].second]; // Want to buy a
      }
    }
  }
  printf("%d", out);
}


