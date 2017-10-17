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
  int n, x;
  scanf("%d %d", &n, &x);
  set<int> nums;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.insert(a);
  }
  int out = 0;
  for (int i = 0; i < x; i++) {
    if (nums.find(i) == nums.end()) {
      out++;
    }
  }
  if (nums.find(x) != nums.end()) {
    out++;
  }
  printf("%d", out);
}
