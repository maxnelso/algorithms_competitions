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
  vector<int> moons;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    moons.push_back(a);
  }
  if (moons.size() == 1 && moons[0] != 0 && moons[0] != 15) {
    printf("-1");
    return 0;
  }
  if (moons[moons.size() - 1] == 15) {
    printf("DOWN");
  } else if (moons[moons.size() - 1] == 0) {
    printf("UP");
  } else if (moons[moons.size() - 1] > moons[moons.size() - 2]) {
    printf("UP");
  } else {
    printf("DOWN");
  }
}
