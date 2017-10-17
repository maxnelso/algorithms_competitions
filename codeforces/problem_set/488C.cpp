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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int yangs_hp, yangs_atk, yangs_def;
  int m_hp, m_atk, m_def;
  int h, a, d;
  scanf("%d %d %d", &yangs_hp, &yangs_atk, &yangs_def);
  scanf("%d %d %d", &m_hp, &m_atk, &m_def);
  scanf("%d %d %d", &h, &a, &d);
  int best_cost = 100000;
  for (int i = 0; i <= 200; i++) {
    for (int j = 0; j <= 100; j++) {
      int x = max(0, yangs_atk + i - m_def);
      int y = max(0, m_atk - yangs_def - j);
      if (x == 0) {
        continue;
      }
      int t = (m_hp + x - 1) / x;
      int z = max(0, y * t + 1 -yangs_hp);
      best_cost = min(best_cost, i * a + j * d + z * h);
    }
  }
  printf("%d", best_cost);
}
