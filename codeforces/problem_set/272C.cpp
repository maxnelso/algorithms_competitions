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
int n, m;
int A[MAXN];

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &m);
  long long L = 0;
  long long h1 = 0;
  for (int i = 0; i < m; i++) {
    int w, h;
    scanf("%d %d", &w, &h);
    long long out;
    if (L + h1 > A[w]) {
      out = L + h1;
    } else {
      out = A[w];
    }
    h1 = h;
    L = out;
    cout << out << endl;
  }

}
