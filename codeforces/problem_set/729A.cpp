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
  int n;
  scanf("%d", &n);
  char c[256];
  scanf("%s", c);
  string s(c);
  string out = "";
  for (int i = 0; i < s.size();) {
    if (i + 2 < s.size() && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
      out += "***";
      i += 3;
      while (i + 1 < s.size() && s[i] == 'g' && s[i + 1] == 'o') {
        i += 2;
      }
    } else {
      out += s[i];
      i++;
    }
  }
  printf("%s", out.c_str());
}
