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
  int n;
  scanf("%d", &n);
  long long sum = 0;
  long long out = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    sum += a;
    out = max(out, a);
  }

  double double_n = (double) n;
  double ceiling = ceil(sum / (double_n - 1));
  cout << max(out, (long long) ceiling);


}
