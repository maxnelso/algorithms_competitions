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
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  vector<int> all_lengths = {a, b, c, d};
  bool collinear = false;
  for (int i = 0; i < 4; i++) {
    vector<int> triangle;
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        continue;
      }
      triangle.push_back(all_lengths[j]);
    }
    if (triangle[0] + triangle[1] > triangle[2] &&
        triangle[0] + triangle[2] > triangle[1] &&
        triangle[1] + triangle[2] > triangle[0]) {
      printf("TRIANGLE");
      return 0;
    }
    if (triangle[0] + triangle[1] >= triangle[2] &&
        triangle[0] + triangle[2] >= triangle[1] &&
        triangle[1] + triangle[2] >= triangle[0]) {
      collinear = true;
    }
  }
  if (collinear) {
    printf("SEGMENT");
  } else {
    printf("IMPOSSIBLE");
  }
}
