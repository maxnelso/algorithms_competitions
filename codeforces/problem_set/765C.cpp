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
  int k, a, b;
  scanf("%d %d %d", &k, &a, &b);
  if (a < k && b < k) {
    printf("-1");
    return 0;
  }
  int b_wins = b / k;
  int a_leeway = (k - 1) * b_wins;
  int a_wins = a / k;
  int b_leeway = (k - 1) * a_wins;
  int a_useless = a % k;
  int b_useless = b % k;
  if (b_useless > b_leeway || a_useless > a_leeway) {
    printf("-1");
    return 0;
  }
  printf("%d", a / k + b / k);
}
