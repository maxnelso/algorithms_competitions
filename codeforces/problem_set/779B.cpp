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
  char c[256];
  int k;
  scanf("%s %d", c, &k);
  string s(c);
  for (int i = 0; i < s.size(); i++) {
    int to_use = i;
    int ending_zeroes = 0;
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s[j] != '0') {
        to_use--;
      } else {
        ending_zeroes++;
      }
      if (ending_zeroes == k && to_use >= 0) {
        printf("%d", i);
        return 0;
      }
    }
  }
  printf("%d", (int) s.size() - 1);
}
