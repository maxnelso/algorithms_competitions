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

long long arithmetic_sum(long long a, long long b) {
  return (b - a + 1) * (a + b) / 2;
}

int main () {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  k--;
  long long low = 0;
  long long high = m;
  long long best = -1;
  while (low <= high) {
    long long mid = (high + low) / 2;
    if (mid == 0) {
      mid = 1;
    }
    long long num_left = k;
    long long total = mid;
    //cout << "Looking at " << mid << endl;
    if (num_left > 0) {
      long long start_left = mid - num_left;
      if (start_left <= 0) {
      //  cout << "under left " << start_left;
        total += abs(start_left) + 1;
        start_left = 1;
      }
      total += arithmetic_sum(start_left, mid - 1);
      //cout << "start and end left " << start_left << " " << mid - 1 << endl;
      //cout << "Left sum " << arithmetic_sum(start_left, mid - 1) << endl;
    }
    long long num_right = n - k - 1;
    if (num_right > 0) {
      long long start_right = mid - num_right;
      if (start_right <= 0) {
        total += abs(start_right) + 1;
        start_right = 1;
      }
      //cout << "start and end right" << start_right << " " << mid - 1 << endl;
      total += arithmetic_sum(start_right, mid - 1);
      //cout << "Right sum " << arithmetic_sum(start_right, mid - 1) << endl;
    }
    //cout << "Total " << total << endl;
    if (total <= m) {
      if (mid >= best) {
        best = mid;
      }
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << best;
}
