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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> heights(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &heights[i]);
  }

  long long current_sum = 0;
  for (int i = 0; i < k; i++) {
    current_sum += heights[i];
  }

  long long best_sum = current_sum;
  long long best_index = 0;
  for (int i = k; i < n; i++) {
    current_sum -= heights[i - k];
    current_sum += heights[i];
    if (current_sum < best_sum) {
      best_sum = current_sum;
      best_index = i - k + 1;
    }
  }

  cout << best_index + 1;
}
