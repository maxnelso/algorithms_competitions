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
  int a, b;
  vector<pair<int, int>> points;
  for (int i = 0; i < n + 1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    pair<int, int> point = make_pair(a, b);
    points.push_back(point);
  }

  for (int i = 0; i < points.size(); i++) {
    pair<int, int> start = points[i];
    pair<int, int> end = points[(i + 1) % points.size()];
  }
}
