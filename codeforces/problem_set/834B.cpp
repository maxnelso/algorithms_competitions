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
  int n, k;
  string s;
  cin >> n >> k >> s;
  //printf("%d %d %s hello\n", n, k, s.c_str());
  //printf("%s hello\n", s.c_str());
  vector<int> lasts(26); //
  for (int i = 0; i < s.size(); i++) {
    lasts[s[i]] = i;
  }
  set<char> current_open;
  for (int i = 0; i < s.size(); i++) {
    if (current_open.find(s[i]) == current_open.end()) {
      current_open.insert(s[i]);
    }
    if (lasts[s[i]] == i) {
      current_open.erase(s[i]);
    }
    if (current_open.size() > k) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
