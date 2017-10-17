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

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  long long n;
  cin >> n;
  vector<long long> nums;

  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    nums.push_back(a);
  }

  sort(nums.begin(), nums.end());
  long long m = nums[0];
  long long min_count = count(nums.begin(), nums.end(), m);
  long long ma = nums[nums.size() - 1];
  long long max_count = count(nums.begin(), nums.end(), ma);

  if (ma == m) {
    cout << (ma - m) << " " << (((min_count - 1) * (1 + min_count - 1)) / 2);
  } else {
    cout << (ma - m) << " " << (min_count * max_count);
  }

}
