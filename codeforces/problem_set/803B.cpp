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
  vector<int> out;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
    out.push_back(n + 1);
  }
  int last = -n;
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      last = i;
    }
    out[i] = i - last;
  }

  last = 2 * n;
  for (int i = n - 1; i >= 0; i--) {
    if (nums[i] == 0) {
      last = i;
    }
    out[i] = min(out[i], last - i);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", out[i]);
  }


}
