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

double dist(double x, double y) {
  return sqrt(x * x + y * y);
}

int main () {
  int r, d;
  scanf("%d %d", &r, &d);
  int n;
  scanf("%d", &n);
  int out = 0;
  for (int i = 0; i < n; i++) {
    int x, y, r1;
    scanf("%d %d %d", &x, &y, &r1);
    //printf("Looking at %d %d %d\n", x, y, r1);
    if (dist(x, y) < r1) {
      continue;
    }
    double vX = -x;
    double vY = -y;
    double magV = sqrt(vX * vX + vY * vY);
    double aX = x + vX / magV * r1;
    double aY = y + vY / magV * r1;
    if (dist(aX, aY) < r - d) {
     continue;
    }
    double oppositeX = x - (aX - x);
    double oppositeY = y - (aY - y);

    // cout << "old " << aX << " " << aY << " " << oppositeX <<  " " << oppositeY << endl;
    if (dist(oppositeX, oppositeY) > r) {
     continue;
    }
    out++;
  }
  printf("%d", out);
}
