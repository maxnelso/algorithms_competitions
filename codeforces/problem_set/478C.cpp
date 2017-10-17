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
  long long red, g, b;
  cin >> red >> g >> b;
  vector<long long> balloons = {red, g, b};
  sort(balloons.begin(), balloons.end());

  long long can = (balloons[0] + balloons[1]) * 2;
  if (can >= balloons[2]) {
    cout << (balloons[0] + balloons[1] + balloons[2]) / 3;
  } else {
    cout << (balloons[0] + balloons[1]);
  }
}
