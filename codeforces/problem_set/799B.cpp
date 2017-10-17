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
  vector<int> prices;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    prices.push_back(a);
  }
  vector<int> fronts;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    fronts.push_back(a);
  }
  vector<int> backs;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    backs.push_back(a);
  }

  map<pair<int, int>, set<int>> ma;

  for (int i = 0; i < n; i++) {
    ma[make_pair(fronts[i], backs[i])].insert(prices[i]);
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int color;
    scanf("%d", &color);
    const int INF = 1000000005;
    int min_cost = INF;
    for (int j = 1; j <= 3; j++) {
      pair<int, int> p = make_pair(j, color);
      if (ma.find(p) != ma.end()) {
        min_cost = min(min_cost, *(ma[p].begin()));
      }

      p = make_pair(color, j);
      if (ma.find(p) != ma.end()) {
        min_cost = min(min_cost, *(ma[p].begin()));
      }
    }
    if (min_cost == INF) {
      printf("-1 ");
    } else {
      printf("%d ", min_cost);

      for (int j = 1; j <= 3; j++) {
        pair<int, int> p = make_pair(j, color);
        if (ma.find(p) != ma.end() && *(ma[p].begin()) == min_cost) {
          ma[p].erase(min_cost);
          if (ma[p].empty()) {
            ma.erase(ma.find(p));
          }
          break;
        }

        p = make_pair(color, j);
        if (ma.find(p) != ma.end() && *(ma[p].begin()) == min_cost) {
          ma[p].erase(min_cost);
          if (ma[p].empty()) {
            ma.erase(ma.find(p));
          }
          break;
        }
      }

    }
  }
}
