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
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  vector<int> copy_nums = nums;
  sort(nums.begin(), nums.end());
  int diffs = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] != copy_nums[i]) {
      diffs++;
    }
  }

  if (diffs == 2 || diffs == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
}
