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
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int n;
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    int z;
    scanf("%d", &z);
    if (z > b && z < c) {
      total++;
    }
  }

  printf("%d", total);
}