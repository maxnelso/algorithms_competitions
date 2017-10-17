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

long long n;
long long k;

bool works(long long a) {
  long long sum = (a * (k + (k - a + 1))) / 2;
  // cout << "Sum before " << a << " " << sum << endl;
  sum -= a - 1;
  // cout << "Sum for " << a << " " << sum << endl;
  return sum >= n;
}

int main () {
  cin >> n >> k;
  if (n == 1) {
    printf("0");
    return 0;
  }
  long long low = 1;
  long long high = k + 1;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (works(mid)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (high == k + 1) {
    cout << -1;
    return 0;
  }
  cout << low;
}
