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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  sort(nums.rbegin(), nums.rend());
  long long out = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      out += (long long) (n - i) * (long long) nums[i];
    } else {
      out += (long long) (n - i + 1) * (long long) nums[i];
    }
  }
  cout << out;
}
