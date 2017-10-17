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
int N; long long d[2005][2005];
int used[2005];
vector<pair<int, long long> > adj[2005];
bool verif[2005][2005];

bool good(int loc, int par = -1, int pard = 0) {
  used[loc] = true;
  if(par != -1) adj[loc].push_back(make_pair(par, pard));

  priority_queue<pair<int, int>> cc;
  for (int i = 0; i < N; i++) {
    if (used[i]) {
      continue;
    }
    cc.push(make_pair(-1 * d[loc][i], i));
  }

  while (true) {
    while(!cc.empty() && used[cc.top().second]) cc.pop();
    if (cc.empty()) {
      return true;
    }
  }


}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      scanf("%d", &a);
      d[i][j] = a;
    }
  }
  bool good = true;
  // Check symmetry
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        if (d[i][j] != 0) {
          good = false;
        }
      } else {
        if (d[i][j] != d[j][i] || d[i][j] == 0 || d[j][i] == 0) {
          good = false;
        }
      }
    }
  }
  if (!good) {
    printf("YES");
  } else {
  }
}
