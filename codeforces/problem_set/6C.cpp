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
  vector<int> chocolates;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    chocolates.push_back(a);
  }
  if (n == 1) {
    printf("1 0");
    return 0;
  }
  int a_index = 0;
  int b_index = n - 1;
  int a_time = chocolates[a_index++];
  int b_time = chocolates[b_index--];
  int a_ate = 1;
  int b_ate = 1;
  while (true) {
    while (a_time <= b_time) {
      int next_index = a_index;
      if (next_index > b_index) {
        break;
      }
      a_time += chocolates[a_index++];
      a_ate++;
    }
    //printf("a time %d %d %d\n", a_time, a_ate, a_index);
    int next_index = a_index;
    if (next_index > b_index) {
      break;
    }
    while (b_time < a_time) {
      int next_index = b_index;
      if (next_index < a_index) {
        break;
      }
      b_time += chocolates[b_index--];
      b_ate++;
    }
    //printf("b time %d %d %d\n", b_time, b_ate, b_index);
    next_index = b_index;
    if (next_index < a_index) {
      break;
    }
  }
  printf("%d %d", a_ate, b_ate);
}
