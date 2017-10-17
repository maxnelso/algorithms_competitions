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
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  long long out = 0;
  vector<int> positive_odds;
  vector<int> all_odds;
  int m = 10e6;
  for (int i = 0; i < n; i++) {
    out += max(0, nums[i]);
    if (nums[i] % 2) {
      m = min(m, abs(nums[i]));
    }
  }
  if (out % 2 == 0) {
    out -= m;
  }
  cout << out;
}
