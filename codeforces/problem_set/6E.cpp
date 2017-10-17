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


int h[1000005];
map<int, int> counts;

int get_max() {
  if (counts.empty()) {
    return 0;
  }
  auto iter = counts.end();
  iter--;
  return iter->first;
}

int get_min() {
  if (counts.empty()) {
    return INT_MAX;
  }
  return counts.begin()->first;
}


int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    h[i] = a;
  }
  int biggest_size = 0;
  vector<int> beginnings;
  int end = 0;
  for (int i = 0; i < n; i++) {
    while (end < n && h[end] - get_min() <= k && get_max() - h[end] <= k) {
      counts[h[end]]++;
      if (end - i > biggest_size) {
        biggest_size = end - i;
        beginnings.clear();
      }
      if (end - i == biggest_size) {
        beginnings.push_back(i);
      }
      end++;
    }
    counts[h[i]]--;
    if (counts[h[i]] == 0) {
      counts.erase(h[i]);
    }
  }
  printf("%d %d\n", biggest_size + 1, beginnings.size());
  for (int i = 0; i < beginnings.size(); i++) {
    printf("%d %d\n", beginnings[i] + 1, beginnings[i] + biggest_size + 1);
  }
}
