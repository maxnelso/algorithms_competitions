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

double dist(long long x1, long long x2, long long y1, long long y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main () {
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if ((by - ay) * (cx - bx) == (cy - by) * (bx - ax)) {
    printf("No");
    return 0;
  }

  double area = .5 * abs((ax - cx) * (by - ay) - (ax - bx) * (cy - ay));
  double radius = (dist(ax, ay, bx, by) * dist(ax, ay, cx, cy) * dist(bx, by, cx, cy)) / ((double) 4 * area);
  double s1 = 2 * radius * asin(dist(ax, ay, bx, by) / ((double) 2 * radius));
  double s2 = 2 * radius * asin(dist(bx, by, cx, cy) / ((double) 2 * radius));
  if (s1 - s2 <= .00000001) {
    printf("Yes");
    return 0;
  }
  printf("No");
  return 0;
  /*
  double ma = (double) (by - ay) / (double) (bx - ax);
  double mb = (double) (cy - by) / (double) (cx - bx);
  cout << ma << endl;
  cout << mb << endl;
  double center_x = (ma * mb * (ay - cy) + mb * (ax + bx) - ma * (bx + cx)) / ((double) 2 * (mb - ma));
  cout << center_x;
  */

}
