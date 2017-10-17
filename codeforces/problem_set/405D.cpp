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

const int N = 1000000;
int a[N + 1];

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x] = 1;
  }
}
