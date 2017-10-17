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
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }

  vector<long long> pows;
  pows.push_back(1);
  const int MOD = 1000000007;
  for (int i = 1; i < n + 2; i++) {
    pows.push_back((pows[i - 1] * 2) % MOD);
  }
  sort(nums.rbegin(), nums.rend());
  long long out = 0;
  for (int i = 0; i < nums.size(); i++) {
    long long bigger_than = (n - 1) - i;
    long long smaller_than = i;
    out += (pows[bigger_than] * nums[i]) % MOD;
    out = out % MOD;
    out -= (pows[smaller_than] * nums[i]) % MOD;
    if (out < 0) {
      out += MOD;
    }
  }
  cout << out;
}
