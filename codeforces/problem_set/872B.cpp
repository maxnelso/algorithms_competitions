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
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  if (k == 1) {
    sort(nums.begin(), nums.end());
    printf("%d", nums[0]);
  } else if (k == 2) {
    vector<int> forwards;
    forwards.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
      forwards.push_back(min(forwards[i - 1], nums[i]));
    }
    vector<int> backwards;
    backwards.push_back(nums[nums.size() - 1]);
    for (int i = n - 2; i >= 0; i--) {
      backwards.push_back(min(backwards[n - i - 2], nums[i]));
    }
    int out = INT_MIN;
    for (int i = 0; i < n; i++) {
      out = max(out, max(forwards[i], backwards[n - i - 1]));
    }
    printf("%d", out);
  } else {
    sort(nums.begin(), nums.end());
    printf("%d", nums[nums.size() - 1]);
  }
}
