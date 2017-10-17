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
  int n, m;
  scanf("%d %d", &n, &m);
  queue<pair<int, int>> as;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    as.push(make_pair(a, i+1));
  }
  while (as.size() != 1) {
    pair<int,int> front = as.front();
    as.pop();
    if (front.first - m <= 0) {
      continue;
    } else {
      as.push(make_pair(front.first - m, front.second));
    }
  }
  pair<int,int> front = as.front();
  printf("%d", front.second);
}
