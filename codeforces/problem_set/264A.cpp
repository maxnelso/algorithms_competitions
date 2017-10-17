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

struct fraction {
  long long numerator;
  long long denominator;
};

int main () {
  string s;
  cin >> s;
  int start = 0;
  int end = s.size() - 1;
  vector<int> out(s.size());
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'l') {
      out[end--] = i + 1;
    } else {
      out[start++] = i + 1;
    }
  }

  for (int i = 0; i < s.size(); i++) {
    printf("%d\n", out[i]);
  }
}
