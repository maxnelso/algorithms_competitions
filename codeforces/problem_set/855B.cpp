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

const long long NEG_INF = (long long) -10e19;

int main () {
  long long n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<long long> nums;
  vector<long long> dp = {NEG_INF, NEG_INF, NEG_INF};
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        dp[0] = max(dp[0], p * a);
      } else if (j == 1) {
        dp[1] = max(dp[1], dp[0] + q * a);
      } else {
        dp[2] = max(dp[2], dp[1] + r * a);
      }
    }
  }
  cout << dp[2];
}
