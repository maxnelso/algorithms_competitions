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

  long long exponent = 0;
  while (n > 1) {
    n /= 4;
    exponent++;
  }
  sort(nums.rbegin(), nums.rend());
  long long next_power = 1;
  long long out = 0;
  for (long long i = 0; i < nums.size(); i++) {
    out += nums[i] * (exponent + 1);
    if (i + 1 >= next_power) {
      next_power *= 4;
      exponent--;
    }
  }
  cout << out;
}
