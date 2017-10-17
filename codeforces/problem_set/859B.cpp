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
  int best = 0;
  for (int i = 1; i < 100000; i++) {
    if (i * i > n) {
      break;
    }
    best = i;
  }
  int current = 4 * best;
  int left = n - (best * best);
  int counter = 0;
  while (counter < best && left > 0) {
    if (counter == 0) {
      current -= 1;
      current += 3;
    }
    left--;
    counter++;
  }
  counter = 0;
  while (counter < best && left > 0) {
    if (counter == 0) {
      current -= 1;
      current += 3;
    }
    left--;
    counter++;
  }
  printf("%d", current);
}
