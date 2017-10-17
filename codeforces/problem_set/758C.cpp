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

long long n, m, k, x, y;

long long count_seat(int a, int b) {
  long long questions_per_cycle = 0;
  if (n == 1) {
    questions_per_cycle = m;
  } else {
    questions_per_cycle = (n - 2) * 2 * m + 2 * m;
  }
  long long cycles = k / questions_per_cycle;
  long long left = k - (cycles * questions_per_cycle);
  int row = 1;
  int col = 1;
  int backwards = false;
  int after = 0;
  while (left > 0) {
    if (row == a && col == b) {
      after++;
    }
    left--;
    col++;
    if (row == n && col == m + 1) {
      row = n - 1;
      col = 1;
      backwards = true;
    } else if (col == m + 1) {
      col = 1;
      row = backwards ? row - 1 : row + 1;
    }
  }
  if (a == 1 || a == n) {
    return after + cycles;
  } else {
    return after + 2 * cycles;
  }
}

int main () {
  cin >> n >> m >> k >> x >> y;
  long long best;
  if (n > 1) {
    best = max(max(count_seat(1, 1), count_seat(2, 1)), count_seat(n - 1, 1));
  } else {
    best = count_seat(1, 1);
  }
  long long mini = count_seat(n, m);
  cout << best << " " << mini << " " << count_seat(x, y);
  //cout << " " << count_seat(x, y) << " " << mini;
}
