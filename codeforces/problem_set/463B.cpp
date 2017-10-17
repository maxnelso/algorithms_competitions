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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n;
  scanf("%d", &n);
  vector<int> heights;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    heights.push_back(a);
  }
  long long out = (long long) heights[0];
  long long current = 0;
  for (int i = 1; i < n; ++i) {
    if (heights[i] - heights[i-1] <= 0) {
      current += (long long ) heights[i-1] - (long long )heights[i];
    } else {
      if (heights[i] - heights[i-1] > current) {
        out += (long long) heights[i] - (long long) heights[i-1] - current;
        current = 0;
      } else {
        current -= (long long) heights[i] - (long long) heights[i-1];
      }
    }
  }
  cout << out;

}
