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
  int h, m, s, t1, t2;
  scanf("%d %d %d %d %d", &h, &m, &s, &t1, &t2);
  h = h * 10 + 1;
  m = m * 2 + 1;
  s = s * 2 + 1;
  t1 = t1 * 10;
  t2 = t2 * 10;
  vector<int> nums = {h, m, s, t1, t2};
  stable_sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] % 2 == 0 && nums[(i + 1) % nums.size()] % 2 == 0) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
