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

vector<long long> sums;

long long get_sum(int l, int r) {
  if (l == 0) {
    return sums[r];
  }
  return sums[r] - sums[l - 1];
}

int bin_search(vector<int>& nums, long long index, int k) {
  long long l = 0;
  long long r = index - 1;
  long long num = nums[index];
  // printf("Looking at num %d %d\n", num, index);
  while (l <= r) {
    long long m = (l + r) / 2;
    // printf("index and m %d %d\n", index, m);
    long long sum_needed = (index - m) * num;
    long long actual_sum = get_sum(m, index - 1);
    // cout << sum_needed << " " << actual_sum << " " << l << " " << r << " " << m << endl;
    if (sum_needed - actual_sum <= k) {
      r = m - 1;
      // printf("new r %d\n", r);
    } else {
      l = m + 1;
      // printf("new l %d\n", l);
    }
  }
  // printf("%d\n", l);
  return index - l + 1;
}

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  sort(nums.begin(), nums.end());
  sums.push_back(nums[0]);
  for (int i = 1; i < n; i++) {
    sums.push_back(sums[i - 1] + nums[i]);
  }

  int best_count = 0;
  int best_num = 0;
  for (int i = 0; i < n; i++) {
    int test = bin_search(nums, i, k);
    if (test > best_count) {
      best_count = test;
      best_num = nums[i];
    }
  }
  printf("%d %d", best_count, best_num);
}
