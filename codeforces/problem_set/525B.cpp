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
  char c[1000000];
  scanf("%s", c);
  string s(c);
  int m;
  scanf("%d", &m);
  vector<int> reverses;
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    a--;
    reverses.push_back(a);
  }
  sort(reverses.begin(), reverses.end());
  long long total = 0;
  vector<int> sums(s.size());
  for (int i = 0; i < reverses.size(); i++) {
    int a = reverses[i];
    sums[a]++;
  }
  for (int i = 1; i < sums.size(); i++) {
    sums[i] = sums[i] + sums[i-1];
  }
  string out;
  for (int i = 0; i < sums.size(); i++) {
    int mirror = s.size() - i - 1;
    if (i >= sums.size() / 2) {
      if (sums[mirror] % 2 == 0) {
        out += s[i];
      } else {
        out += s[mirror];
      }
    } else {
      if (sums[i] % 2 == 0) {
          out += s[i];
      } else {
        out += s[mirror];
      }
    }
  }
  printf("%s", out.c_str());
}
