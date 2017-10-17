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

int sums[100005];

int main () {
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    sums[i + 1] = sums[i] + (s[i] == s[i + 1]);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    printf("%d\n", sums[r] - sums[l]);
  }

}
