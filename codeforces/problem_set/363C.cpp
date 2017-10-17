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

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  char c[200001];
  scanf("%s", c);
  string s(c);
  string out = "";
  for (int i = 0; i < s.size(); i++) {
    bool bad = false;
    if (out.size() >= 2) {
      if (s[i] == out[out.size() - 1] && s[i] == out[out.size() - 2]) {
        bad = true;
      }
    }
    if (out.size() >= 3) {
      if (s[i] == out[out.size() - 1] && out[out.size() - 2] == out[out.size() - 3]) {
        bad = true;
      }
    }
    if (!bad) {
      out += s[i];
    }
  }
  printf("%s", out.c_str());
}
