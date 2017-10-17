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
  int n, m;
  scanf("%d %d", &n, &m);
  set<int> seen;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    seen.insert(a);
  }
  int i = 1;
  vector<int> out;
  while (m >= i) {
    if (seen.find(i) != seen.end()) {
      i++;
      continue;
    }
    out.push_back(i);
    m -= i;
    i++;
  }
  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i]);
  }
}
