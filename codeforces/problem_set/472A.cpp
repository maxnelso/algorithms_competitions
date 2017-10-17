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

bool is_prime(int n) {
  for (int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int i = 4; i < n; i++) {
    if (!is_prime(i) && !is_prime(n - i)) {
      printf("%d %d", i, n - i);
      break;
    }
  }
}
