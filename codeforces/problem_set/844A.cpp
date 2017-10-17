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
  string s;
  cin >> s;
  int k;
  scanf("%d", &k);
  if (s.size() < k) {
    printf("impossible");
    return 0;
  }
  sort(s.begin(), s.end());
  auto it = unique(s.begin(), s.end());
  s.resize(distance(s.begin(), it));
  printf("%d", max(0, k - (int) s.size()));
}
