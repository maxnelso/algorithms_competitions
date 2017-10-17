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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

bool check(vector<int> &boys, vector<int> &bikes, int k, int a) {
  if (k > boys.size()) {
    return false;
  }
  for (int i = 0; i < k; i++) {
    if (boys[k - i - 1] >= bikes[i]) {
      continue;
    }
    if (boys[k - i - 1] + a < bikes[i]) {
      return false;
    }
    a -= bikes[i] - boys[k - i - 1];
  }
  return true;
}

int get_total(vector<int> &boys, vector<int> &bikes, int k, int a) {
  int out = 0;
  for (int i = 0; i < k; i++) {
    if (boys[k - i - 1] >= bikes[i]) {
      out += bikes[i];
      continue;
    }
    out += boys[k - i - 1];
    a -= bikes[i] - boys[k - i - 1];
  }
  return max(out - a, 0);
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m, a;
  scanf("%d %d %d", &n, &m, &a);
  vector<int> boys;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    boys.push_back(a);
  }
  vector<int> bikes;
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    bikes.push_back(a);
  }
  sort(boys.begin(), boys.end());
  sort(bikes.begin(), bikes.end());
  int low = 0;
  int high = min(m, n);
  int best = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(boys, bikes, mid, a)) {
      if (mid > best) {
        best = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  printf("%d %d", best, get_total(boys, bikes, best, a));

}
