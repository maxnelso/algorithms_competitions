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
  unordered_map<string, int> seen;
  for (int i = 0; i < n; i++) {
    char c[100];
    scanf("%s", c);
    string s(c);
    if (seen.find(s) != seen.end()) {
      printf("%s%d\n", s.c_str(), seen[s]);
      seen[s]++;
    } else {
      printf("OK\n");
      seen[s] = 1;
    }
  }
}
