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
  vector<int> berles;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    berles.push_back(a);
  }
  auto it = max_element(berles.begin(), berles.end());
  int m = *it;
  int out = 0;
  for (int i = 0; i < berles.size(); i++) {
    out += m - berles[i];
  }
  printf("%d", out);

}
