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

pair<int, int> get_interval(int start, vector<int>& nums) {
  if (start == nums.size() - 1) {
    return make_pair(start + 1, start + 1);
  }

  // increasing
  int end = start;
  while (end < nums.size() - 1 && nums[end + 1] >= nums[end]) {
    end++;
  }

  // decreasing
  while (end < nums.size() - 1 && nums[end + 1] <= nums[end]) {
    end++;
  }

  return make_pair(start + 1, end + 1);
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }


  // Build intervals
  vector<pair<int, int>> increasing;
  vector<pair<int, int>> decreasing;
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      increasing.push_back(make_pair(start + 1, i + 1));
    } else {
      if (nums[i + 1] < nums[i]) {
        increasing.push_back(make_pair(start + 1, i + 1));
        start = i + 1;
      }
    }
  }

  start = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      decreasing.push_back(make_pair(start + 1, i + 1));
    } else {
      if (nums[i + 1] > nums[i]) {
        decreasing.push_back(make_pair(start + 1, i + 1));
        start = i + 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    auto increasing_it = lower_bound(increasing.begin(), increasing.end(), make_pair(a, 0));
    if ((increasing_it->first) != a) {
      increasing_it--;
    }
    int increasing_end = increasing_it->second;
    if (increasing_end >= b) {
      printf("Yes\n");
      continue;
    }

    auto decreasing_it = lower_bound(decreasing.begin(), decreasing.end(), make_pair(increasing_end + 1, 0));
    if ((decreasing_it->first) != a) {
      decreasing_it--;
    }
    if (decreasing_it->second >= b) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
