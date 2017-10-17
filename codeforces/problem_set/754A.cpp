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
  int non_zero_index = -1;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a != 0 && non_zero_index == -1) {
      non_zero_index = i;
    }
    nums.push_back(a);
  }
  if (non_zero_index == -1) {
    printf("NO");
    return 0;
  }
  int total_sum = accumulate(nums.begin(), nums.end(), 0);
  if (total_sum != 0) {
    printf("YES\n");
    printf("1\n");
    printf("1 %d", n);
    return 0;
  }
  printf("YES\n");
  printf("2\n");
  printf("1 %d\n", non_zero_index + 1);
  printf("%d %d", non_zero_index + 2, n);
  return 0;
}
