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
  char s[5];
  char t[5];
  scanf("%s", s);
  scanf("%s", t);
  string out;
  int count = 0;
  while (s[0] > t[0] && s[1] > t[1]) {
    s[0]--;
    s[1]--;
    out += "LD\n";
    count++;
  }
  while (s[0] < t[0] && s[1] > t[1]) {
    s[0]++;
    s[1]--;
    out += "RD\n";
    count++;
  }
  while (s[0] > t[0] && s[1] < t[1]) {
    s[0]--;
    s[1]++;
    out += "LU\n";
    count++;
  }
  while (s[0] < t[0] && s[1] < t[1]) {
    s[0]++;
    s[1]++;
    out += "RU\n";
    count++;
  }
  while (s[0] < t[0]) {
    s[0]++;
    out += "R\n";
    count++;
  }
  while (s[0] > t[0]) {
    s[0]--;
    out += "L\n";
    count++;
  }
  while (s[1] > t[1]) {
    s[1]--;
    out += "D\n";
    count++;
  }
  while (s[1] < t[1]) {
    s[1]++;
    out += "U\n";
    count++;
  }
  printf("%d\n", count);
  printf("%s", out.c_str());
}
