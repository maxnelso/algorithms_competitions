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
  if (s.size() < 3) {
    printf("%s", s.c_str());
    return 0;
  }
  string vowels = "aeiou";
  string out = "";
  int i = 0;
  for (i = 0; i < s.size() - 2;) {
    char start = s[i];
    bool good_string = true;
    for (int j = i; j <= i + 2; j++) {
      char c = s[j];
      if (vowels.find(c) != string::npos) {
        good_string = true;
        break;
      }
      if (s[j] != start) {
        good_string = false;
      }
    }
    if (good_string) {
      out += s[i];
      i++;
    } else {
      out += s[i];
      out += s[i+1];
      out += " ";
      i++;
      i++;
    }
  }

  while (i < s.size()) {
    out += s[i++];
  }
  printf("%s", out.c_str());
}
