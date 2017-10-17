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

bool ends_with(string full_string, string ending) {
  if (full_string.length() >= ending.length()) {
    return (0 == full_string.compare(full_string.length() - ending.length(), ending.length(), ending));
  } else {
    return false;
  }
}

bool starts_with(string full_string, string ending) {
  if (full_string.length() >= ending.length()) {
    return (0 == full_string.compare(0, ending.size(), ending));
  } else {
    return false;
  }
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    bool freda = false;
    bool rainbow = false;
    if (ends_with(s, "lala.")) {
      freda = true;
    }
    if (starts_with(s, "miao.")) {
      rainbow = true;
    }
    if ((freda && rainbow) || (!freda && !rainbow)) {
      printf("OMG>.< I don't know!\n");
    } else if (freda) {
      printf("Freda's\n");
    } else {
      printf("Rainbow's\n");
    }
  }
}
