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

long long a[2000];
long long fac[20];

void set_fact() {
  long out = 1;
  int index = 0;
  while (index < 19) {
    fac[index++] = out;
    out = out * (index + 2);
  }
}



int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  set_fact();
}
