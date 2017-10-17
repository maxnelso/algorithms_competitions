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
  long long r, g, b;
  cin >> r >> g >> b;
  long long out = 0;
  long long test_start = max(0ll, min(min(r, g), b) - 10);
  long long test_end = min(min(r, g), b);
  for (long long i = test_start; i <= test_end; i++) {
    long long rc = r;
    long long gc = g;
    long long bc = b;
    long long new_out = i;
    rc -= i;
    gc -= i;
    bc -= i;
    new_out += rc / 3;
    new_out += gc / 3;
    new_out += bc / 3;
    out = max(out, new_out);
  }
  cout << out;
}
