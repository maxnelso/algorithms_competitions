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
using ll = long long;

using namespace std;
priority_queue <ll> q;
ll const N = 1e3 + 10;
ll const M = 1e6 + 10;

ll R[N], C[N];
ll r[M], c[M];
int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, m, k, p;
  scanf("%d %d %d %d", &n, &m, &k, &p);
    long long r[100010];
  long long c[100010];
  for (ll i=0,cc; i<m; ++i) for (ll j=0; j<n; ++j) {
    cin >> cc;
    R[i] += cc, C[j] += cc;
  }
  q = priority_queue <ll> (R, R+m);
  for (ll i=0; i<k; ++i) {
    ll cc = q.top(); q.pop();
    r[i+1] = r[i] + cc;
    q.push(cc-n*p);
  }
    q = priority_queue <ll> (C, C+n);
    for (ll i=0; i<k; ++i) {
    ll cc = q.top(); q.pop();
    c[i+1] = c[i] + cc;
    q.push(cc-m*p);
  }
  long long result = max(r[k], c[k]);
  for (int i = 1; i < k; i++) {
    long long temp = r[i] + c[k-i] - i * (k - i) * p;
    result = max(result, temp);
  }
  cout << result;
}
