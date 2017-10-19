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

int sum_digits(int x) {
  if (x == 0) {
    return 0;
  }
  return x % 10 + sum_digits(x / 10);
}

int main () {
  int n;
  scanf("%d", &n);
  vector<int> result;
  for (int sum = 0; sum <= 100 && sum <= n; sum++) {
    int x = n - sum;
    if (sum_digits(x) == sum) {
      result.push_back(x);
    }
  }

  sort(result.begin(), result.end());
  printf("%d\n", result.size());
  for (int i = 0; i < result.size(); i++) {
    printf("%d ", result[i]);
  }
}
