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

const int MINF = INT_MIN / 2;

vector<int> arrange(vector<pair<int, int>>& fountains) {
  sort(fountains.begin(), fountains.end());

  vector<int> maxes;
  for (int i = 0; i < fountains.size(); i++) {
    if (i) {
      maxes.push_back(max(maxes[i - 1], fountains[i].second));
    } else {
      maxes.push_back(fountains[0].second);
    }
  }

  return maxes;
}

int get_best(vector<pair<int, int>> &fount, vector<int> &maxes, int funds, int inx_max) {
  if (fount.size() == 0 || inx_max < 0) {
    return MINF;
  }

  pair<int, int> key = {funds + 1, -1};
  auto it = lower_bound(fount.begin(), fount.end(), key);
  if (it == fount.begin()) {
    return MINF;
  }
  it = prev(it);

  int which = it - fount.begin();
  which = min(which, inx_max);
  return maxes[which];
}


int solve(vector<pair<int, int>>& fount, vector<int>& maxes, int funds) {
  int ans = 0;
  for (int i = 0; i < fount.size(); i++) {
    if (fount[i].first > funds) continue;
    ans = max(ans, fount[i].second + get_best(fount, maxes, funds - fount[i].first, i - 1));
  }
  return ans;
}


int main () {
  int n, c, d;
  scanf("%d %d %d\n", &n, &c, &d);
  vector<pair<int, int>> coins, diamonds;
  for (int i = 0; i < n; i++) {
    int beauty, cost;
    char type;
    scanf("%d %d %c", &beauty, &cost, &type);
    if (type == 'C') {
      coins.push_back(make_pair(cost, beauty));
    } else {
      diamonds.push_back(make_pair(cost, beauty));
    }
  }
  sort(coins.begin(), coins.end());
  sort(diamonds.begin(), diamonds.end());
  vector<int> cmax = arrange(coins);
  vector<int> dmax = arrange(diamonds);
  int seperate = max(0, get_best(coins, cmax, c, INT_MAX) + get_best(diamonds, dmax, d, INT_MAX));

  int one_of_each = max(solve(coins, cmax, c), solve(diamonds, dmax, d));
  printf("%d", max(seperate, one_of_each));


}
