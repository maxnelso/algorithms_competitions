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

int pw1 = 1 << 17;
int pw2 = 1 << 18;

int main () {
  int n, x;
  scanf("%d %d", &n, &x);
  if (n == 1) {
    printf("YES\n");
    printf("%d", x);
    return 0;
  } else if (n == 2 && x == 0) {
    printf("NO\n");
    return 0;
  } else if (n == 2) {
    printf("YES\n");
    printf("%d %d", 0, x);
    return 0;
  }
  printf("YES\n");
  int current = 0;
  for (int i = 1; i <= n - 3; i++) {
    printf("%d ", i);
    current ^= i;
  }
  if (current == x) {
    printf("%d %d %d", pw1, pw2, pw1 ^ pw2);
  } else {
    printf("%d %d %d", 0, pw1, pw1 ^ x ^ current);
  }
}
