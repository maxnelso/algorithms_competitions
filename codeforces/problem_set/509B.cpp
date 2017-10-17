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
#include <sstream>
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int min_not_zero(vector<int> pebbles) {
  int m = 10000;
  for (int i = 0; i < pebbles.size(); i++) {
    if (pebbles[i] != 0 && pebbles[i] < m) {
      m = pebbles[i];
    }
  }
  if (m == 10000) {
    return 0;
  }
  return m;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> pebbles;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    pebbles.push_back(a);
  }
  vector<string> out(n);
  int color = 1;
  while (k > 0)  {
    int m = min_not_zero(pebbles);
    if (color == 1) {
      m = min_not_zero(pebbles) + 1;
    } else {
      m = min(m, 1);
    }
    for (int i = 0; i < pebbles.size(); i++) {
      int x = min(pebbles[i], m);
      for (int j = 0; j < x; j++) {
        stringstream ss;
        ss << color;
        out[i] = out[i] + ss.str() + " ";
        pebbles[i]--;
      }
    }
    color++;
    k--;
  }
  for (int i = 0; i < pebbles.size(); i++) {
    if (pebbles[i] > 0) {
      printf("NO");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < pebbles.size(); i++) {
    printf("%s\n", out[i].c_str());
  }
}
