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
  long long a_i, b_i;
  cin >> a_i >> b_i;
  bitset<64> a(a_i);
  bitset<64> b(b_i);
  bitset<64> out(0);
  bool diff = false;
  for (int i = 63; i >= 0; i--) {
    if (a[i] != b[i]) {
      diff = true;
    }

    if (diff) {
      out.set(i);
    }
  }

  cout << out.to_ullong();
}
