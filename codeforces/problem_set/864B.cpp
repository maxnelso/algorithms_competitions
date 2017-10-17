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
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int best = 0;
  for (int i = 0; i < s.size(); i++) {
    set<char> seen;
    for (int j = i; j < s.size(); j++) {
      char c = s[j];
      if (isupper(c)) {
        break;
      }
      seen.insert(c);
    }
    best = max(best,(int) seen.size());
  }
  printf("%d", best);
}
