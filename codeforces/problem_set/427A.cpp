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
  int n;
  scanf("%d", &n);
  int police_count = 0;
  int bad = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == -1) {
      if (police_count == 0) {
        bad++;
      } else {
        police_count--;
      }
    } else {
      police_count += a;
    }
  }
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("%d", bad);
}
