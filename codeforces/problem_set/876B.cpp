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

const int MAXN = 100005;

int main () {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  vector<vector<int>> counts(MAXN);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    counts[a % m].push_back(a);
  }
  for (int i = 0; i < MAXN; i++) {
    if (counts[i].size() >= k) {
      printf("Yes\n");
      for (int j = 0; j < k; j++) {
        printf("%d ", counts[i][j]);
      }
      return 0;
    }
  }

  printf("No");
}
