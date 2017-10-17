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

using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a == 100) {
      ones++;
    } else {
      twos++;
    }
  }
  bool good = true;
  for (int i = 0; i <= ones; i++) {
    for (int j = 0; j <= twos; j++) {
      if (i + 2*j == (ones - i) + 2*(twos - j)) {
        printf("YES");
        good = false;
        break;
      }
    }
    if (!good) {
      break;
    }
  }
  if (good) {
    printf("NO");
  }
}
