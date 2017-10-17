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
  long long n, m;
  cin >> n >> m;
  if (n <= m) {
    cout << n << endl;
    return 0;
  }
  long long left = n;
  long long t = m;
  left -= m + 1;
  t++;
  if (left <= 0) {
    cout << t;
    return 0;
  }
  long long solution = (-1 + sqrt(1 + 8 * left)) / 2.0;
  cout << t + solution << endl;
}
