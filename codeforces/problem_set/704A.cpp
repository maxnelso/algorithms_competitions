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

bool mark[300010];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, q;
  scanf("%d %d", &n, &q);

  vector<queue<int>> es(n);
  queue<pair<int, int>> Q;
  int unread = 0;
  for (int i = 0; i < q; i++) {
    int type, x;
    scanf("%d %d", &type, &x);
    if (type == 1) {
      unread++;
      Q.push(make_pair(i + 1, x));
      es[x].insert(i + 1);
    } else if (type == 2) {
      queue<int> &qu = es[x];
      for (auto e : qu) {
        mark[e] = true;
        unread -= es.size();
        es.clear();
      }
    } else {
      while (!Q.empty() && Q.front().first <= x) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        if (mark[a] == false) {
          mark[a] = false;
          es[b].l();
          unread--;
        }
      }
    }
    printf("%d", unread);
  }
}
