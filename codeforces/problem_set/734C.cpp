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
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int x, s;
  scanf("%d %d", &x, &s);
  vector<int> a;
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    a.push_back(q);
  }
  vector<int> b;
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    b.push_back(q);
  }

  vector<int> c;
  for (int i = 0; i < k; i++) {
    int q;
    scanf("%d", &q);
    c.push_back(q);
  }

  vector<int> d;
  for (int i = 0; i < k; i++) {
    int q;
    scanf("%d", &q);
    d.push_back(q);
  }

  m++;
  a.push_back(x);
  b.push_back(0);
  long long best = -1;
  for (int i = 0; i < m; i++) {
    int mana_left = s;
    mana_left -= b[i];
    auto it = upper_bound(d.begin(), d.end(), mana_left);
    int position = it - d.begin() - 1;
    int potions = n;
    long long total_time = 0;
    if (position != -1) {
      potions -= c[position];
    }
    if (potions > 0 && mana_left >= 0) {
      total_time += (long long ) a[i] * (long long ) potions;
    } else if (potions > 0) {
      total_time += (long long ) potions * (long long ) x;
    }
    if (best == -1 || total_time < best) {
      best = total_time;
    }
  }
  cout << best;
}
