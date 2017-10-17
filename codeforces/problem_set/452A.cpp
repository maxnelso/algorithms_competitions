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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  vector<string> pokemon = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
  int n;
  scanf("%d", &n);
  char c[256];
  scanf("%s", c);
  string s(c);
  bool good[8];
  memset(good, true, 8);
  for (int i = 0; i < pokemon.size(); ++i) {
    if (pokemon[i].size() != n) {
      continue;
    }
    bool bad = false;
    for (int j = 0; j < n; ++j) {
      if (pokemon[i][j] != s[j] && s[j] != '.') {
        bad = true;
        break;
      }
    }
    if (!bad) {
      printf("%s", pokemon[i].c_str());
    }
  }
}
