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
  int zeroes = 0;
  int out = 0;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
    out += a == 1;
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) {
      zeroes++;
      int ones = 0;
      for (int j = i + 1; j < n; j++) {
        ones += nums[j] == 1;
      }
      out = max(out, zeroes + ones);
    }
  }
  printf("%d", out);
}
