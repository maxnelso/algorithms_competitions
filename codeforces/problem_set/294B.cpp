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

int main () {
  int n;
  scanf("%d", &n);
  vector<int> ones;
  vector<int> twos;
  int total_ones_width = 0;
  int total_twos_width = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 1) {
      ones.push_back(b);
      total_ones_width += b;
    } else {
      twos.push_back(b);
      total_twos_width += b;
    }
  }
  sort(ones.rbegin(), ones.rend());
  sort(twos.rbegin(), twos.rend());

  int min_thickness = 100000;
  for (int i = 0; i <= ones.size(); i++) {

    int one_thickness = i;
    int one_width = total_ones_width;
    for (int j = 0; j < i; j++) {
      one_width -= ones[j];
    }

    for (int j = 0; j <= twos.size(); j++) {
      int two_thickness = j * 2;
      int two_width = total_twos_width;
      for (int k = 0; k < j; k++) {
        two_width -= twos[k];
      }

      // printf("i j %d %d\n", i, j);
      // printf("%d %d %d %d\n", one_thickness, one_width, two_thickness, two_width);
      if (one_thickness + two_thickness >= one_width + two_width && one_thickness + two_thickness < min_thickness) {
        min_thickness = one_thickness + two_thickness;
      }
    }
  }

  printf("%d", min_thickness);
}
