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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  string four = "4 * 3 = 12\n2 * 1 = 2\n12 * 2 = 24";
  string five = "5 + 4 = 9\n9 + 3 = 12\n12 * 2 = 24\n24 * 1 = 24";
  int n;
  scanf("%d", &n);
  if (n <= 3) {
    printf("NO");
  } else {
    printf("YES\n");
    if (n == 4) {
      printf("%s", four.c_str());
    } else if (n == 5) {
      printf("%s", five.c_str());
    } else if (n % 2 == 0) {
      int count = 0;
      while (n != 4) {
        printf("%d - %d = 1\n", n, n - 1);
        n = n - 2;
        count++;
      }
      printf("%s\n", four.c_str());
      for (int i = 0; i < count; i++) {
        if (i != count - 1) {
          printf("24 * 1 = 24\n");
        } else {
          printf("24 * 1 = 24");
        }
      }
    } else {
      int count = 0;
      while (n != 5) {
        printf("%d - %d = 1\n", n, n - 1);
        n = n - 2;
        count++;
      }
      printf("%s\n", five.c_str());
      for (int i = 0; i < count; i++) {
        if (i != count - 1) {
          printf("24 * 1 = 24\n");
        } else {
          printf("24 * 1 = 24");
        }
      }
    }

  }
}
