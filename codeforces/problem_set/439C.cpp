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
  int n, k, p;
  scanf("%d %d %d", &n, &k, &p);
  vector<int> evens;
  vector<int> odds;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a % 2 == 0) {
      evens.push_back(a);
    } else {
      odds.push_back(a);
    }
  }

  int EVEN = p;
  int ODD = k - p;

  int LEFTOVER = odds.size() - ODD;
  if (odds.size() < ODD || LEFTOVER % 2 == 1) {
    printf("NO");
    return 0;
  }

  if (evens.size() + LEFTOVER / 2 < EVEN) {
    printf("NO");
    return 0;
  }

  printf("YES\n");
  vector<vector<int>> out;
  for (int i = 0; i < k; i++) {
    if (i < ODD) {
      vector<int> single_odd;
      single_odd.push_back(odds[odds.size() - 1]);
      odds.pop_back();
      out.push_back(single_odd);
    } else {
      if (evens.size()) {
        vector<int> single_even;
        single_even.push_back(evens[evens.size() - 1]);
        evens.pop_back();
        out.push_back(single_even);
      } else {
        vector<int> two_odds;
        two_odds.push_back(odds[odds.size() - 1]);
        odds.pop_back();
        two_odds.push_back(odds[odds.size() - 1]);
        odds.pop_back();
        out.push_back(two_odds);
      }
    }
  }

  while (evens.size()) {
    out[0].push_back(evens[evens.size() - 1]);
    evens.pop_back();
  }

  while (odds.size()) {
    out[0].push_back(odds[odds.size() - 1]);
    odds.pop_back();
  }

  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i].size());
    for (int j = 0; j < out[i].size(); j++) {
      printf("%d ", out[i][j]);
    }
    printf("\n");
  }
}
