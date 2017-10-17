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
  long long fibs[300050];
  long long a = 1;
  long long b = 1;
  fibs[0] = 1;
  fibs[1] = 1;
  for (int i = 2; i <= 300008; i++) {
    int temp = a;
    a = b;
    b = temp + b;
    fibs[i] = b;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> as;
  for (int i = 0; i < n; i++) {
    int z;
    scanf("%d", &z);
    as.push_back(z);
  }
  for (int i = 0; i < m; i++) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      for (int j = l; j <= r; j++) {
        as[j-1] += fibs[j - l];
      }
    } else {
      int score = 0;
      for (int j = l; j <= r; j++) {
        score += (as[j-1] % 1000000009);
      }
      printf("%d\n", score);
    }
  }
}
