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

const int MAXN = 1005;

double memo[MAXN][MAXN][2];
bool found[MAXN][MAXN][2];

double solve(int w, int b, bool princess) {
  if (w == 0) {
    return 0;
  }

  if (found[w][b][princess]) {
    return memo[w][b][princess];
  }


  double out = 0;
  if (princess) {
    double win_chance = (double) w / (double) (b + w);
    out += win_chance;
    if (b > 0) {
      double lose_chance = 1 - win_chance;
      out += lose_chance * solve(w, b - 1, false);
    }
  } else {
    if (b > 0) {
      double dragon_lose_chance = (double) b / (double) (b + w);
      if (w > 0) {
        double white_mouse_leaves = (double) w / (double) (b + w - 1);
        out += dragon_lose_chance * white_mouse_leaves * solve(w - 1, b - 1, true);
      }
      if (b > 1) {
        double black_mouse_leaves = (double) (b - 1) / (double) (b + w - 1);
        out += dragon_lose_chance * black_mouse_leaves * solve(w, b - 2, true);
      }
    }
  }
  found[w][b][princess] = true;
  memo[w][b][princess] = out;
  return out;
}

int main() {
  int w, b;
  scanf("%d %d", &w, &b);
  printf("%.10f", solve(w, b, true));
}
