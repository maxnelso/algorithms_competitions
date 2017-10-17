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

struct event {
  bool actor;
  int low, high, k;
  int index;

  bool operator<(const event& y) const {
    if (low != y.low) return low < y.low;
    return actor > y.actor;
  }
};

vector<event> events(200005);
int answer[200005];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    events[i].low = a;
    events[i].high = b;
    events[i].actor = false;
    events[i].index = i;
  }
  int m;
  scanf("%d", &m);
  for (int i = n; i < n + m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    events[i].low = a;
    events[i].high = b;
    events[i].actor = true;
    events[i].k = c;
    events[i].index = i;
  }

  map<pair<int, int>, int> available;

  sort(events.begin(), events.begin() + n + m);
  bool good = true;
  for (int i = 0; i < n + m; i++) {
    if (events[i].actor) {
      available[make_pair(events[i].high, events[i].index)] = events[i].k;
    } else {
      auto it = available.lower_bound(make_pair(events[i].high, -1));
      if (it == available.end()) {
        good = false;
        break;
      }
      answer[events[i].index] = it->first.second - n + 1;
      it->second--;
      if (it->second == 0) {
        available.erase(it);
      }
    }
  }

  if (good) {
    printf("YES\n");
    for (int i = 0; i < n; i++) {
      printf("%d ", answer[i]);
    }
    printf("\n");
  } else {
    printf("NO");
  }
}
