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
  vector<char> top = {'q','w','e','r','t','y','u','i','o','p'};
  vector<char> middle = {'a','s','d','f','g','h','j','k','l',';'};
  vector<char> bottom = {'z','x','c','v','b','n','m',',','.','/'};
  char shift;
  scanf("%c", &shift);
  char c[256];
  scanf("%s", c);
  string s(c);
  string out = "";
  for (int i = 0; i < s.size(); i++) {
    if (shift == 'R') {
      if (find(top.begin(), top.end(), s[i]) != top.end()) {
        out += *(find(top.begin(), top.end(), s[i]) - 1);
      }
      if (find(middle.begin(), middle.end(), s[i]) != middle.end()) {
        out += *(find(middle.begin(), middle.end(), s[i]) - 1);
      }
      if (find(bottom.begin(), bottom.end(), s[i]) != bottom.end()) {
        out += *(find(bottom.begin(), bottom.end(), s[i]) - 1);
      }
    } else {
      if (find(top.begin(), top.end(), s[i]) != top.end()) {
        out = out + *(find(top.begin(), top.end(), s[i]) + 1);
      }
      if (find(middle.begin(), middle.end(), s[i]) != middle.end()) {
        out = out + *(find(middle.begin(), middle.end(), s[i]) + 1);
      }
      if (find(bottom.begin(), bottom.end(), s[i]) != bottom.end()) {
        out = out + *(find(bottom.begin(), bottom.end(), s[i]) + 1);
      }
    }
  }
  printf("%s", out.c_str());
}
