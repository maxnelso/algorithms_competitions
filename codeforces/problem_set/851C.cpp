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

struct point_pair {
  pair<int, int> indices;
  double angle;
}

struct point {
  int a, b, c, d, e;
}

int main () {
  int n;
  scanf("%d", &n);
  vector<point> points;
  for (int i = 0; i < n; i++) {
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    point t;
    t.a = a;
    t.b = b;
    t.c = c;
    t.d = d;
    t.e = e;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      point p;

    }
  }
}
