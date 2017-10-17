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
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  vector<long long> b;
  for (int i = 0; i < m; i++) {
    long long y;
    cin >> y;
    b.push_back(y);
  }
  int i = 0;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  long long out = 0;
  while (i < a.size() && i < b.size() && a[i] < b[i]) {
    out += b[i] - a[i];
    i++;
  }
  cout << out;
}
