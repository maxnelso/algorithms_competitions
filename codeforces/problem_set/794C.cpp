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
  string a, b;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  int a_i = 0;
  int b_i = 0;
  string out = "";
  while (out.size() != a.size()) {
    out += a[a_i++];
    if (out.size() == a.size()) {
      break;
    }
    out += b[b_i++];
  }
  printf("%s", out.c_str());
}
