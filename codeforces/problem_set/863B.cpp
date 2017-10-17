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

int solve(vector<int>& nums, int skip1, int skip2) {
  int out = 0;
  int first_index = -1;
  for (int i = 0; i < nums.size(); i++) {
    if (i == skip1 || i == skip2) {
      continue;
    }
    if (first_index != -1) {
      out += nums[i] - nums[first_index];
      first_index = -1;
    } else {
      first_index = i;
    }
  }
  return out;
}

int main () {
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < 2 * n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  sort(nums.begin(), nums.end());
  int best = 1000000;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j <  nums.size(); j++) {
      best = min(best, solve(nums, i, j));
    }
  }
  printf("%d", best);
}
