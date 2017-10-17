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
  int n, k;
  scanf("%d %d", &n, &k);

  int current = n;
  vector<int> out;
  while (true) {
    bool found = false;
    for (int j = 2; j < current; j++) {
      if (current % j == 0) {
        out.push_back(j);
        current /= j;
        found = true;
        break;
      }
    }
    if (!found) {
      break;
    }
  }
  out.push_back(current);
  if (out.size() < k) {
    printf("-1");
    return 0;
  }
  while (out.size() > k) {
    int last = out[out.size() - 1];
    int second_to_last = out[out.size() - 2];
    int new_ele = last * second_to_last;
    out.pop_back();
    out.pop_back();
    out.push_back(new_ele);
  }
  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i]);
  }
  return 0;
}
