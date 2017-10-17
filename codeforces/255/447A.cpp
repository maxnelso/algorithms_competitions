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
  int p, n;
  scanf("%d %d", &p, &n);
  map<int, bool> seen;
  bool found = false;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    a = a % p;
    if (seen.find(a) != seen.end()) {
      printf("%d\n", i+1);
      found = true;
      break;
    }
    seen[a] = true;
  }
  if (!found) {
    printf("%d\n", -1);
  }
}
