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

#define point pair<int, int>
#define x first
#define y second

using namespace std;
const int MAX = 100010;


int d(point p)
{
    return abs(p.x) + abs(p.y);
}
bool comp(point a, point b)
{
    return (d(a) < d(b));
}

int main () {
  int n;
  scanf("%d", &n);
  pair<int, int> points[MAX];
  int out = 6 * n;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = make_pair(x, y);
    if (x == 0 || y == 0) {
      out -= 2;
    }
  }
  sort(points, points + n, comp);
  int index = 0;
  printf("%d\n", out);
  for (int i = 0; i < n; i++) {
    pair<int, int> p = points[i];
    if (p.first > 0) {
      printf("1 %d R\n", p.first);
    } else if (p.first < 0) {
      printf("1 %d L\n", abs(p.first));
    }
    if (p.second > 0) {
      printf("1 %d U\n", p.second);
    } else if (p.second < 0) {
      printf("1 %d D\n", abs(p.second));
    }
    printf("2\n");
    if (p.second > 0) {
      printf("1 %d D\n", p.second);
    } else if (p.second < 0) {
      printf("1 %d U\n", abs(p.second));
    }
    if (p.first > 0) {
      printf("1 %d L\n", p.first);
    } else if (p.first < 0) {
      printf("1 %d R\n", abs(p.first));
    }

    printf("3\n");
  }
}
