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
  setvbuf(stdout, NULL, _IONBF, 0);
  set<string> current;
  int out = 0;
  string s;
  while (getline(cin, s)) {
    if (s[0] == '+') {
      string name = string(s.begin() + 1, s.end());
      current.insert(name);
    } else if (s[0] == '-') {
      string name = string(s.begin() + 1, s.end());
      current.erase(current.find(name));
    } else {
      int l = s.size() - s.find(':') - 1;
      l *= current.size();
      out += l;
    }
  }
  printf("%d", out);
}
