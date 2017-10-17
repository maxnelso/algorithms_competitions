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

int main () {
  int n, m, min, max;
  scanf("%d %d %d %d", &n, &m, &min, &max);
  vector<int> nums;
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  int min_ele = *min_element(nums.begin(), nums.end());
  int max_ele = *max_element(nums.begin(), nums.end());
  if (min_ele < min || max_ele > max) {
    printf("Incorrect");
  } else if (m == n - 1) {
    if (min_ele == min || max_ele == max) {
      printf("Correct");
    } else {
      printf("Incorrect");
    }
  } else {
    printf("Correct");
  }

}
