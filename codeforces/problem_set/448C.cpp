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

vector<int> nums;

int solve(int l, int r, int h) {
  if (l > r) {
    return 0;
  }

  int out = 0;
  for (int i = l; i <= r; i++) {
    out += nums[i] > h;
  }

  if (l == r) {
    return out;
  }

  int min_index = l;
  int min_ele = nums[l];
  for (int i = l; i <= r; i++) {
    if (nums[i] < min_ele) {
      min_ele = nums[i];
      min_index = i;
    }
  }

  int added = min_ele - h;
  return min(out, added + solve(l, min_index - 1, min_ele) + solve(min_index + 1, r, min_ele));
}

int main () {
  int n;
  scanf("%d", &n);
  nums.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  printf("%d", solve(0, nums.size() - 1, 0));
}
