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
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> counts(k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &counts[i]);
  }

  int available_fours = n;
  int available_twos = 2 * n;
  int available_ones = 0;

  for (int i = 0; i < k; i++) {
    while (counts[i] >= 3) {
      if (available_fours > 0) {
        available_fours--;
        counts[i] -= 4;
      } else if (available_twos > 0) {
        available_twos--;
        counts[i] -= 2;
      } else {
        printf("NO");
        return 0;
      }
    }
  }

  int need_ones = 0;
  for (int i = 0; i < k; i++) {
    if (counts[i] == 2) {
      if (available_twos > 0) {
        counts[i] = 0;
        available_twos--;
      } else if (available_fours > 0) {
        counts[i] = 0;
        available_fours--;
        available_ones++;
      } else {
        need_ones += 2;
      }
    } else if (counts[i] == 1) {
      need_ones++;
    }
  }
  if (need_ones > available_ones + available_twos + available_fours * 2) {
    printf("NO");
    return 0;
  }
  printf("YES");
  return 0;
}
