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


vector<pair<int, pair<int, int>> edges[300005];
vector<int> out;
bool visited[30005];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    edges[x].push({y, {z, i}})
    edges[y].push({x, {z, i}})
  }
  int u;
  scanf("%d", &u);
  priority_queue<pair<pair<long long, int>, pair<int, int> > > pq;


}
