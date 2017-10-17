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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  char c[256];
  scanf("%s", c);
  string s(c);
  bool changed = false;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i -1]) {
      if (changed) {
        printf("NO");
        return 0;
      }
      changed = true;
    }
  }
  if (!changed && s.size() % 2 == 0) {
    printf("NO");
  } else {
    printf("YES");
  }
  return 0;
}
