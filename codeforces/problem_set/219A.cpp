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
  int k;
  scanf("%d", &k);
  char c[10000];
  scanf("%s", c);
  string s(c);
  map<char, int> counts;
  for (int i = 0; i < s.size(); i++) {
    counts[s[i]]++;
  }
  string out = "";
  for (auto& p : counts) {
    if (p.second % k != 0) {
      printf("-1");
      return 0;
    }
    for (int i = 0; i < p.second / k; i++) {
      out += p.first;
    }
  }

  for (int i = 0; i < k; i++) {
    printf("%s", out.c_str());
  }
}
