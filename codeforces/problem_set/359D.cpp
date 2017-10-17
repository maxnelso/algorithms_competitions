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
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  int best = 0;
  vector<int> bests;
  for (int i = 0; i < n;) {
    int l = i;
    int r = i;
    while (l > 0 && nums[l - 1] % nums[i] == 0) {
      l--;
    }
    while (r < n - 1 && nums[r + 1] % nums[i] == 0) {
      r++;
    }

    i = r + 1;

    if (r - l > best) {
      bests.clear();
      best = r - l;
    }
    if (r - l == best) {
      bests.push_back(l + 1);
    }
  }
  printf("%d %d\n", bests.size(), best);
  for (int i = 0; i < bests.size(); i++) {
    printf("%d ", bests[i]);
  }
}
