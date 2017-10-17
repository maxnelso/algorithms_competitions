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
  int n, v;
  scanf("%d %d", &n, &v);
  vector<int> sellers;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    bool found = false;
    for (int j = 0; j < a; j++) {
      int b;
      scanf("%d", &b);
      if (b < v && !found) {
        sellers.push_back(i + 1);
        found = true;
      }
    }
  }
  printf("%d\n", sellers.size());
  for (int i = 0; i < sellers.size(); i++) {
    printf("%d ", sellers[i]);
  }
}
