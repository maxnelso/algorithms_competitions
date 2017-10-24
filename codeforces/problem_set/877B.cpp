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

string s;

int get_sum(const vector<int>& sums, int l, int r) {
  if (l == 0) {
    return sums[r];
  }
  return sums[r] - sums[l - 1];
}

int main () {
  cin >> s;
  int n = s.size();
  vector<int> as(n);
  as[0] = s[0] == 'a';
  for (int i = 1; i < n; i++) {
    as[i] = as[i - 1] + (s[i] == 'a');
  }
  vector<int> bs;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') {
      bs.push_back(i);
    }
  }
  // print_container(bs);
  // print_container(as);
  // printf("%d\n", as[n - 1]);
  int out = max(as[n - 1], (int) bs.size());
  for (int i = 0; i < bs.size(); i++) {
    for (int j = i + 1; j < bs.size(); j++) {
      int first_b = bs[i];
      int last_b = bs[j];
      out = max(out, (j - i + 1) + get_sum(as, 0, first_b) + get_sum(as, last_b, n - 1));
    }
  }
  printf("%d", out);
}
