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
  long long out = 1;
  const int MOD = 1000000007;
  vector<string> names(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    names[i] = s;
  }
  for (int i = 0; i < m; i++) {
    set<char> seen;
    for (int j = 0; j < n; j++) {
      seen.insert(names[j][i]);
    }
    out = out * seen.size();
    out = out % MOD;
  }
  cout << out;
}
