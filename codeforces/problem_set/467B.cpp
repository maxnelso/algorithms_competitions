#include <vector>
#include <bitset>
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
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> nums;
  for (int i = 0; i < m + 1; ++i) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  bitset<32> fedor(nums[nums.size() - 1]);
  int total = 0;
  for (int i = 0; i < nums.size() - 1; ++i) {
    bitset<32> x(nums[i]);
    int count = 0;
    for (int j = 0; j < 32; ++j) {
      if (x[j] != fedor[j]) {
        count++;
      }
    }
    if (count <= k) {
      total++;
    }
  }
  printf("%d", total);
}
