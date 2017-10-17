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
  string out = "";
  while (n > 3) {
    out += "1";
    n -= 2;
  }
  if (n == 3) {
    out = "7" + out;
  } else if (n == 2) {
    out = "1" + out;
  }

  printf("%s", out.c_str());

}
