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
  int n;
  scanf("%d", &n);
  char c[256];
  scanf("%s", c);
  string s(c);
  int count = 1;
  if (s[0] != '0') {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '1') {
        count++;
      } else {
        count++;
        break;
      }
    }
  }
  printf("%d", count);
}
