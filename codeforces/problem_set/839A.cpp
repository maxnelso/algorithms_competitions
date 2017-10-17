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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  int candies = 0;
  for (int i = 0; i < n; i++) {
    candies += nums[i];
    int a = min(candies, 8);
    k -= a;
    candies -= a;
    if (k <= 0) {
      printf("%d", i + 1);
      return 0;
    }
  }

  printf("-1");
}
