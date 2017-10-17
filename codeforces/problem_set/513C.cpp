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

int a[5], b[5];
int j, n;

double solve(int pos, int bigger, int same) {
  if (bigger == 2) {
    return 0.0;
  }
  if (pos == n) {
    if (bigger == 0 && same != 2) {
      return 0.0;
    }
    if (same == 0) {
      return 0.0;
    }
    return 1.0;
  }
  double out = 0.0;
  // Take it as a larger one
  double p;
  if (a[pos] > j) {
    p = 1.0;
  } else if (b[pos] <= j) {
    p = 0.0;
  } else {
    p = (b[pos] - (j + 1) + 1.0) / (b[pos] - a[pos] + 1);
    if (p < 0) {
      p = 0.0;
    }
  }
  //printf("For second price %d and pos %d the probability for a bigger one is %f\n", j, pos, p);
  out += p * solve(pos + 1, bigger + 1, same);
  // Take it as a same one
  if (a[pos] > j) {
    p = 0.0;
  } else if (b[pos] < j) {
    p = 0.0;
  } else {
    if (a[pos] == b[pos]) {
      p = 1.0;
    } else {
      p = 1.0 / (b[pos] - a[pos] + 1);
    }
  }
  out += p * solve(pos + 1, bigger, min(same + 1, 2));
  //printf("For second price %d and pos %d the probability for a same is %f\n", j, pos, p);
  // Take it as a smaller one
  if (b[pos] < j) {
    p = 1.0;
  } else if (a[pos] >= j) {
    p = 0.0;
  } else {
    p = ((j - 1) - a[pos] + 1.0) / (b[pos] - a[pos] + 1);
    if (p < 0) {
      p = 0.0;
    }
  }
  //printf("For second price %d and pos %d the probability for a smaller is %f\n", j, pos, p);
  out += p * solve(pos + 1, bigger, same);
  return out;

}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }
  double out = 0.0;
  for (j = 1; j <= 10000; j++) {
    double answer = solve(0, 0, 0);
    //printf("For j %d answer is %f\n", j, answer);
    out += j * answer;

  }
  printf("%.12f", out);
}
