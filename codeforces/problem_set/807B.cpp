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

bool wins(int s, int me) {
  int i = (s / 50) % 475;
  for (int j = 0; j < 25; j++) {
    i = (i * 96 + 42) % 475;
    if (i + 26 == me) {
      return true;
    }
  }
  return false;
}

int main () {
  int p, x, y;
  scanf("%d %d %d", &p, &x, &y);
  queue<pair<int, int>> q;
  q.push(make_pair(x, 0));
  int tmp_x = x;
  while (tmp_x >= y) {
    if (wins(tmp_x, p)) {
      printf("0");
      return 0;
    }
    tmp_x -= 50;
  }
  while (!q.empty()) {
    int s = q.front().first;
    int d = q.front().second;
    q.pop();
    if (wins(s, p)) {
      printf("%d", d);
      return 0;
    }
    if (s > x) {
      if ((s - x) % 100 == 0) {
        q.push(make_pair(s + 100, d + 1));
        if (s - 50 >= y) {
          q.push(make_pair(s - 50, d));
        }
      } else {
        q.push(make_pair(s + 100, d + 1));
      }
    } else if (s < x) {
      if (s - 50 >= y) {
        q.push(make_pair(s - 50, d));
      }
    } else {
      q.push(make_pair(s + 100, d + 1));
      if (s - 50 >= y) {
        q.push(make_pair(s - 50, d));
      }
    }
  }
  return 0;
}
