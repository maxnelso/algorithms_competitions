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
  int n;
  scanf("%d", &n);
  vector<int> strengths(n);
  vector<bool> marked(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &strengths[i]);
  }

  sort(strengths.begin(), strengths.end());
  int out = 0;
  for (int i = 0; i < n; i++) {
    if (marked[i]) {
      continue;
    }
    marked[i] = true;
    out++;
    int c = 1;
    for (int j = i + 1; j < n; j++) {
      if (marked[j]) {
        continue;
      }

      if (strengths[j] < c) {
        continue;
      }

      marked[j] = true;
      c++;
    }
  }
  printf("%d", out);
}

