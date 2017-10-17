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
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<long long> counts(n);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    counts[l]++;
    if (r < n - 1) {
      counts[r + 1]--;
    }
  }

  sort(a.rbegin(), a.rend());
  vector<long long> actual_counts(n);
  long long v = 0;
  for (int i = 0; i < n; i++) {
    v += counts[i];
    actual_counts[i] = v;
  }
  sort(actual_counts.rbegin(), actual_counts.rend());
  long long out = 0;
  for (int i = 0; i < n; i++) {
    out += a[i] * actual_counts[i];
  }

  cout << out;
}
