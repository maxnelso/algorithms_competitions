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
  int a, b, h, w, n;
  scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);

  vector<int> extensions;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    extensions.push_back(a);
  }

  sort(extensions.rbegin(), extensions.rend());

  if (max(a, b) <= max(w, h) && min(a, b) <= min(w, h)) {
    printf("0");
    return 0;
  }

  for (int i = 1; i <= extensions.size(); i++) {
    for (int j = 0; j <= i; j++) {
      vector<bool> mask(i);
      for (int k = 0; k < j; k++) {
        mask[mask.size() - 1 - k] = 1;
      }
      do {
        // print_container(mask);
        int a_mult = 1;
        int b_mult = 1;
        for (int k = 0; k < i; k++) {
          if (mask[k]) {
            a_mult *= extensions[k];
          } else {
            b_mult *= extensions[k];
          }
        }
        // printf("%d %d\n", a_mult, b_mult);
        if ((w * a_mult >= a && h * b_mult >= b) ||
            (w * b_mult >= a && h * a_mult >= b) ||
            (w * a_mult >= b && h * b_mult >= a) ||
            (w * b_mult >= b && h * a_mult >= a)) {
          printf("%d", i);
          return 0;
        }
      } while (next_permutation(mask.begin(), mask.end()));
    }
  }
  printf("-1");
  return 0;
}
