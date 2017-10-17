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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> as;
  vector<int> bs;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    as.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    bs.push_back(x);
  }

  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  for (int i = 0; i < as.size(); i++) {
    for (int j = 0; j < bs.size(); j++) {
      if (as[i] == bs[j]) {
        printf("%d", as[i]);
        return 0;
      }
    }
  }
  if (as[0] < bs[0]) {
    printf("%d%d", as[0], bs[0]);
  } else {
    printf("%d%d", bs[0], as[0]);
  }
}
