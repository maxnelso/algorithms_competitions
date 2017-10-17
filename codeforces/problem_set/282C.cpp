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
  string a, b;
  cin >> a >> b;
  if (a.size() != b.size()) {
    printf("NO");
    return 0;
  }
  bool a_all_zeroes = true;
  bool b_all_zeroes = true;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '1') {
      a_all_zeroes = false;
      break;
    }
  }
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == '1') {
      b_all_zeroes = false;
      break;
    }
  }
  if (a_all_zeroes && b_all_zeroes) {
    printf("YES");
    return 0;
  }
  if ((a_all_zeroes && !b_all_zeroes) || (!a_all_zeroes && b_all_zeroes)) {
    printf("NO");
    return 0;
  }
  printf("YES");
}
