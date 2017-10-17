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

long long get_sum(const vector<long long>& sums, int l, int r) {
  if (l == 0) {
    return sums[r];
  }
  return sums[r] - sums[l - 1];
}

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<long long> a(n), sum(n);
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    a[i] = num;
  }
  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  pair<int, int> answer = make_pair(n - 2 * k, n - k); // a start, b start

  long long answer_sum = get_sum(sum, n - 2 * k, n - k - 1) + get_sum(sum, n - k, n - 1);
  pair<int, long long> suffix_max = make_pair(n - k, get_sum(sum, n - k, n - 1));
  for (int i = n - 2 * k - 1; i >= 0; i--) {
    long long current_sum = get_sum(sum, i + k, i + 2 * k - 1);
    if (current_sum >= suffix_max.second) {
      suffix_max = make_pair(i + k, current_sum);
    }
    current_sum = get_sum(sum, i, i + k - 1) + suffix_max.second;

    if (current_sum >= answer_sum) {
      answer_sum = current_sum;
      answer = make_pair(i, suffix_max.first);
    }
  }

  printf("%d %d", answer.first + 1, answer.second + 1);
}
