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
  vector<int> nums(9);
  for (int i = 0; i < 9; i++) {
    scanf("%d", &nums[i]);
  }

  vector<int> digit_count;
  for (int i = 0; i < 9; i++) {
    digit_count.push_back(n / (nums[i]));
  }

  int best_digit = -1;
  int best_digit_count = 0;
  int least_cost = INT_MAX;
  for (int i = 0; i < 9; i++) {
    int cost = digit_count[i] * nums[i];
    if ((digit_count[i] > best_digit_count) || (digit_count[i] == best_digit_count && cost <= least_cost)) {
      best_digit = i + 1;
      best_digit_count = digit_count[i];
      least_cost = cost;
    }
  }

  if (best_digit_count == 0) {
    printf("-1");
    return 0;
  }

  string out;
  for (int i = 0; i < best_digit_count; i++) {
    out.push_back('0' + best_digit);
  }

  n = n - (nums[best_digit - 1] * (best_digit_count));
  // printf("%d\n", n);
  for (int i = 0; i < out.size(); i++) {
    int num = out[i] - '0';
    // printf("num %d\n", num);
    for (int j = 8; j >= 0; j--) {
      // printf("%d %d %d %d\n", n, nums[num -1], nums[j], n + nums[num - 1] - nums[j]);
      if (n + nums[num - 1] - nums[j] >= 0) {
        // printf("made it\n");
        out[i] = '0' + j + 1;
        n = n + nums[num - 1] - nums[j];
        break;
      }
    }
  }

  printf("%s", out.c_str());
}
