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

const int MAXN = 100005;
vector<int> nums;

int find_right(int low_index) {
  int l = low_index;
  int r = nums.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[low_index] * 2 >= nums[mid]) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  // printf("For low_index %d right_index is %d\n", low_index, l - 1);
  return l - 1;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }

  sort(nums.begin(), nums.end());
  int out = MAXN;
  for (int i = 0; i < nums.size(); i++) {
    out = min(out, i + (int) (nums.size() - find_right(i) - 1));
  }
  printf("%d", out);
}
