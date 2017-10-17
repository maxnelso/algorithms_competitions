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
  long long a, b;
  cin >> a >> b;
  long long c = 1;
  bool flag = true;
  while (true) {
    if (flag) {
      a -= c;
      if (a < 0) {
        printf("Vladik");
        return 0;
      }
    } else {
      b -= c;
      if (b < 0) {
        printf("Valera");
        return 0;
      }
    }
    c++;
    flag = !flag;
  }
}
