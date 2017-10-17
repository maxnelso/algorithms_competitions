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

int a[6];
int b[6];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    b[x]++;
  }

  int diffs = 0;
  for (int i = 1; i <= 5; i++) {
    int diff = abs(a[i] - b[i]);
    if (diffs % 2 != 0) {
      printf("-1");
      return 0;
    }
    diffs += diff;
  }
  printf("%d", diffs / 4);
}
