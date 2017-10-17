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

const int MAXN = (int) 10e5 + 10;

using namespace std;

string a, b;

bool check(int len, string& s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != a[i % len]) {
      return false;
    }
  }
  return true;
}

int main () {
  cin >> a >> b;
  int out = 0;
  for (int i = 1; i < MAXN; i++) {
    if (a.size() % i == 0 && b.size() % i == 0 && check(i, a) && check(i, b)) {
      out++;
    }
  }
  printf("%d", out);
}
