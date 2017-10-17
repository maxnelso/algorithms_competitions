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

  if (k >= s.size()) {
    int out = k + s.size();
    if (out % 2 == 1) {
      out--;
    }
    printf("%d", out);
    return 0;
  }

  int old = s.size();
  s.resize(s.size() + k);
  for (int i = old; i < s.size(); i++) {
    s[i] = '?';
  }

  int max_tandem = 0;
  for (int l = 0; l < s.size(); l++) {
    for (int j = 0; j < s.size(); j++) {
      int out = 0;
      for (int k = j; k < j + l; k++) {
        if (k + l >= s.size()) {
          break;
        }
        if (s[k] != s[k + l] && s[k + l] != '?') {
          break;
        }
        out++;
      }
      if (out == l) {
        max_tandem = l;
      }
    }
  }
  printf("%d", max_tandem * 2);
}
