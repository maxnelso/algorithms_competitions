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
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != '0') {
      break;
    }
    if (s[s.size() - i - 1] != '0') {
      printf("NO");
      return 0;
    }
  }
  int start = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '0') {
      start = i;
      break;
    }
  }

  int end = s.size() - 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] != '0') {
      end = i;
      break;
    }
  }
  int len = end - start + 1;
  string stripped = s.substr(start, len);
  for (int i = 0; i <= stripped.size() / 2; i++) {
    if (stripped[i] != stripped[stripped.size() - i - 1]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}
