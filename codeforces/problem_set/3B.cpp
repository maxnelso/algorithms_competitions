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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, v;
  scanf("%d %d", &n, &v);
  vector<pair<int, int> > twos;
  vector<pair<int, int> > ones;
  for (int i = 0; i < n; i++) {
    int t, p;
    scanf("%d %d", &t, &p);
    if (t == 1) {
      ones.push_back(make_pair(p, i + 1));
    } else {
      twos.push_back(make_pair(p, i + 1));
    }
  }
  sort(twos.rbegin(), twos.rend());
  sort(ones.rbegin(), ones.rend());
  int num_ones = std::min((int) ones.size(), v);
  int num_twos = std::min((int) twos.size(), (v - num_ones) / 2);
  vector<int> ones_sums = {0};
  vector<int> twos_sums = {0};
  for (int i = 0; i < ones.size(); i++) {
    ones_sums.push_back(ones_sums[i] + ones[i].first);
  }
  for (int i = 0; i < twos.size(); i++) {
    twos_sums.push_back(twos_sums[i] + twos[i].first);
  }
  int current_sum = ones_sums[num_ones] + twos_sums[num_twos];
  int best_sum = current_sum;
  int best_ones = num_ones;
  int best_twos = num_twos;
  while (num_ones > 0) {
    num_ones--;
    int num_twos = std::min((int) twos.size(), (v - num_ones) / 2);
    current_sum = ones_sums[num_ones] + twos_sums[num_twos];
    if (current_sum > best_sum) {
      best_sum = current_sum;
      best_ones = num_ones;
      best_twos = num_twos;
    }
  }
  printf("%d\n", best_sum);
  for (int i = 0; i < best_twos; i++) {
    printf("%d ", twos[i].second);
  }
  for (int i = 0; i < best_ones; i++) {
    printf("%d ", ones[i].second);
  }
  return 0;
}
