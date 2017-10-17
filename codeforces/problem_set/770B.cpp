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

long long compute_sum(string s) {
  long long out = 0;
  for (int i = 0; i < s.size(); i++) {
    out += s[i] - '0';
  }
  return out;
}

int main () {
  long long n;
  cin >> n;
  string s = to_string(n);
  long long best = n;
  long long best_sum = compute_sum(s);
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '0') {
      string c = s;
      c[i]--;
      for (int j = i + 1; j < c.size(); j++) {
        c[j] = '9';
      }
      long long a = stoll(c);
      if (compute_sum(c) > best_sum) {
        best = a;
        best_sum = compute_sum(c);
      }
    }
  }

  cout << best;
}
