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
  int n, h;
  scanf("%d %d", &n, &h);
  double split_area = (1 * .5f * h) / (double) n;
  double theta = atan2(h, .5);
  double previous_area = 0;
  for (int i = 0; i < n - 1; i++) {
    double x = sqrt(split_area / tan(theta));
    double height = tan(theta) * x;
    split_area += (x * height - previous_area);
    previous_area = x * height;
    cout.precision(20);
    cout << height << " ";
  }
}
