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
  map<char, int> counts;
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    char c;
    scanf("%c", &c);
    counts[c]++;
    if (counts[c] > k) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
}
