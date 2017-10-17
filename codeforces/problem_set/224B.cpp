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

const int MAXN = (int) 10e5 + 5;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> nums(n);
  vector<int> counts(MAXN);
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
    counts[nums[i]]++;
  }

  int initial_count = 0;
  for (int i = 0; i < counts.size(); i++) {
    initial_count += counts[i] != 0;
  }

  if (k == 1) {
    printf("1 1");
    return 0;
  }

  if (initial_count < k) {
    printf("-1 -1");
    return 0;
  }

  int i = nums.size() - 1;
  while (initial_count >= k) {
    int a = nums[i--];
    counts[a]--;
    if (counts[a] == 0) {
      initial_count--;
    }
  }

  initial_count++;
  int r = i + 1;
  i = 0;
  while (initial_count >= k) {
    int a = nums[i++];
    counts[a]--;
    if (counts[a] == 0) {
      initial_count--;
    }
  }

  int l = i - 1;
  printf("%d %d", l + 1, r + 1);
}
