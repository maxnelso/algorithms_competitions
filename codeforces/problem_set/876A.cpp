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
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  n--;
  if (n == 0) {
    printf("0");
    return 0;
  }
  vector<int> nums = {a, b, c};
  sort(nums.begin(), nums.end());
  if (nums[0] == a || nums[0] == b) {
    printf("%d", n * nums[0]);
  } else {
    printf("%d", (n - 1) * nums[0] + nums[1]);
  }
}
