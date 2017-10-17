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

double dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1-x2, 2) + pow(y2-y1, 2));
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  if (n == 0) {
    printf("%d %d\n", 0, 1);
    printf("%d %d\n", 0, m);
    printf("%d %d\n", 0, 0);
    printf("%d %d", 0, m-1);
  } else if (m == 0) {
    printf("%d %d\n", 1, 0);
    printf("%d %d\n", n, 0);
    printf("%d %d\n", 0, 0);
    printf("%d %d", n-1, 0);
  } else {
    // quad diagonals
    double diags = dist(1,0,n,m) + dist(n,m,0,0) + dist(0,0,n-1,m);
    double n_side = dist(0,0,n,m) + dist(n,m,0,m) + dist(0,m,n,0);
    double m_side = dist(0,0,n,m) + dist(n,m,n,0) + dist(n,0,0,m);
    if (diags >= n_side && diags >= m_side) {
      printf("%d %d\n", 1, 0);
      printf("%d %d\n", n, m);
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", n-1, m);
    } else if (n_side >= m_side) {
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", n, m);
      printf("%d %d\n", 0, m);
      printf("%d %d\n", n, 0);
    } else {
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", n, m);
      printf("%d %d\n", n, 0);
      printf("%d %d\n", 0, m);
    }
  }
}
