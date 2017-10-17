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

bool adjacent(pair<int, int> a, pair<int, int> b) {
  return (abs(a.first - b.first) + abs(a.second - b.second)) <= 1;
}

int main () {
  char c[150];
  scanf("%s", c);
  string p(c);

  pair<int, int> current = {0, 0};
  vector<pair<int, int>> path;
  path.push_back(current);
  for (int i = 0; i < p.size(); i++) {
    if (p[i] == 'L') {
      current.first--;
    } else if (p[i] == 'R') {
      current.first++;
    } else if (p[i] == 'D') {
      current.second--;
    } else if (p[i] == 'U') {
      current.second++;
    }
    path.push_back(current);
  }

  for (int i = 0; i < path.size(); i++) {
    for (int j = 0; j < i - 1; j++) {
      if (adjacent(path[i], path[j])) {
        printf("BUG");
        return 0;
      }
    }
  }
  printf("OK");
}
