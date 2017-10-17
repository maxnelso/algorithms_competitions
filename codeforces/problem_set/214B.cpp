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
  vector<int> nums;
  bool has_zero = false;
  vector<int> one_diffs;
  vector<int> two_diffs;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    sum += a;
    if (a == 0) {
      has_zero = true;
    }
    if (a % 3 == 1) {
      one_diffs.push_back(a);
    }
    if (a % 3 == 2) {
      two_diffs.push_back(a);
    }
    nums.push_back(a);
  }

 // printf("%d %d", has_zero, sum);
  if (!has_zero) {
    printf("-1");
    return 0;
  }

  sort(one_diffs.begin(), one_diffs.end());
  sort(two_diffs.begin(), two_diffs.end());
  int diff = sum % 3;
  int SENTINEL = 100000;
  pair<int, int> to_remove = {-1, -1};
  if (diff == 0) {
    // all good
  } else if (diff == 1) {
    int best = SENTINEL;
    if (one_diffs.size() >= 1) {
      best = min(best, one_diffs[0]);
      to_remove = {one_diffs[0], -1};
    }
    if (two_diffs.size() >= 2 && two_diffs[0] + two_diffs[1] < best) {
      best = two_diffs[0] + two_diffs[1];
      to_remove = {two_diffs[0], two_diffs[1]};
    }
  } else {
    int best = SENTINEL;
    if (two_diffs.size() >= 1) {
      best = min(best, two_diffs[0]);
      to_remove = {two_diffs[0], -1};
    }
    if (one_diffs.size() >= 2 && one_diffs[0] + one_diffs[1] < best) {
      best = one_diffs[0] + one_diffs[1];
      to_remove = {one_diffs[0], one_diffs[1]};
    }
  }

  if (diff != 0 && to_remove.first == -1) {
    printf("-1");
    return 0;
  }

  if (to_remove.first != -1) {
    nums.erase(find(nums.begin(), nums.end(), to_remove.first));
  }
  if (to_remove.second != -1) {
    nums.erase(find(nums.begin(), nums.end(), to_remove.second));
  }

  sort(nums.rbegin(), nums.rend());
  if (nums[0] == 0) {
    printf("0");
    return 0;
  }
  for (int i = 0; i < nums.size(); i++) {
    printf("%d", nums[i]);
  }
}
