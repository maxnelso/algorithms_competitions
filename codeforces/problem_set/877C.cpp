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
  int n;
  scanf("%d", &n);
  if (n == 2) {
    printf("3\n");
    printf("2 1 2");
    return 0;
  }
  int index = 1;
  string out = "";
  int actions = 0;
  while (n > 0) {
    if (n == 1) {
      n--;
      printf("%
    } else if (n == 2) {
      n -= 2;
    } else {
      n -= 3;
      index += 3;
    }
  }
}
