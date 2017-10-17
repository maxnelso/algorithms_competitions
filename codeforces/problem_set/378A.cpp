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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  int a_wins = 0;
  int b_wins = 0;
  int draw = 0;
  for (int i = 1; i <= 6; ++i) {
    if (abs(i - a) < abs(i - b)) {
      a_wins++;
    } else if (abs(i - a) > abs(i - b)) {
      b_wins++;
    } else {
      draw++;
    }
  }
  printf("%d %d %d", a_wins, draw, b_wins);
  setvbuf(stdout, NULL, _IONBF, 0);
}
