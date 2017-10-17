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

int score(int p, int t) {
  return max(3*p / 10, p - p / 250 * t);
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int misha = score(a, c);
  int vasya = score(b, d);
  if (misha == vasya) {
    printf("Tie");
  } else if (misha > vasya) {
    printf("Misha");
  } else {
    printf("Vasya");
  }
}
