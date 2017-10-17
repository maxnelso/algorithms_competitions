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

long long calculate(vector<int> a) {
  long long sum = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    sum += abs(a[i+1] - a[i]);
  }
  return sum;
}

long long calculate_diff(vector<int> a, int from) {
  long long sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += abs(from - a[i]);
  }
  return sum;
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> nums;
  for (int i = 0; i < m; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  vector<int> fixed;
  fixed.push_back(nums[0]);
  for (int i = 1; i < m; ++i) {
    if (nums[i] != nums[i-1]) {
      fixed.push_back(nums[i]);
    }
  }
  m = fixed.size();
  int max_fixed = *(max_element(fixed.begin(), fixed.end()));
  vector<vector<int>> adjacent(max_fixed + 1, vector<int>());
  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      adjacent[fixed[i]].push_back(fixed[i-1]);
    }
    if (i < m - 1) {
      adjacent[fixed[i]].push_back(fixed[i+1]);
    }
  }
  long long original = calculate(fixed);
  long long change = 0;
  for (int i = 1; i <= max_fixed; ++i) {
    if (adjacent[i].size() > 0) {
      vector<int> b = adjacent[i];
      sort(b.begin(), b.end());
      long long t1 = calculate_diff(b, i);
      long long t2 = calculate_diff(b, adjacent[i][b.size() / 2]);
      change = max(change, t1 - t2);
    }
  }
  cout << original - change << endl;
  setvbuf(stdout, NULL, _IONBF, 0);
}
