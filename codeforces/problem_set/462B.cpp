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
  int n, k;
  scanf("%d %d", &n, &k);
  char c[100005];
  scanf("%s", c);
  string s(c);
  map<char, int> counts;
  map<char, bool> used;
  for (int i = 0; i < s.size(); ++i) {
    if (counts.find(s[i]) == counts.end()) {
      counts[s[i]] = 1;
    } else {
      counts[s[i]]++;
    }
  }
  long long result = 0;
  while (k > 0) {
    int best = 0;
    char best_char = 'a';
    for (map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it) {
      if (used.find(it->first) == used.end()) {
        if (it->second > best) {
          best_char = it->first;
          best = it->second;
        }
      }
    }
    result += (long long) min(k, best)* (long long )min(k, best);
    k -= min(k, best);
    used[best_char] = true;
  }
  cout << result;
}
