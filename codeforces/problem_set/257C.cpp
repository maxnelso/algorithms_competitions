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

const double PI = 3.14159264;

int main () {
  int n;
  scanf("%d", &n);
  vector<double> angles;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    double angle = atan2(a, b);
    if (angle < 0) {
      angle += PI * 2;
    }
    angle *= 180 / PI;
    angles.push_back(angle);
  }
  sort(angles.begin(), angles.end());
  if (angles.size() == 1) {
    printf("0");
    return 0;
  }
  double out = angles[angles.size() - 1] - angles[0];
  for (int i = 0; i < angles.size(); i++) {
    double current = angles[i];
    double previous = angles[(i - 1) % angles.size()];
    out = min(out, previous + 360 - current);
  }
  printf("%f", out);
}
