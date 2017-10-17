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
  int p, q, l, r;
  scanf("%d %d %d %d", &p, &q, &l, &r);
  bool good[1010];
  memset(good, 0, 1010);
  for (int i = 0; i < p; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int j = a; j <= b; j++) {
      good[j] = true;
    }
  }
  map<int, bool> seen;
  bool other_good[1010];
  memset(other_good, 0, 1010);
  int count = 0;
  for (int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int j = l; j <= r; j++) {
      if (seen.find(j) == seen.end()) {
        int low = a + j;
        int high = b + j;
        for (int k = low; k <= high; k++) {
          if (good[k]) {
            seen[j] = true;
            break;
          }
        }

      }
    }
  }
  /*
  int count = 0;
  for (int i = l; i <= r; i++) {
    if (other_good[i] && good[i]) {
      count++;
    }
  }
  print_container(good);
  print_container(other_good);
  */
  printf("%d", seen.size());
}
