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
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  map<int, int> nums;
  map<int, int> labels;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    nums[c] = i;
  }
  bool good = true;
  vector<int> out(n);
  queue<pair<int, int>> singletons;
  for (auto it = nums.begin(); it != nums.end(); it++) {
    if (nums.find(a - it->first) != nums.end() &&
        nums.find(b - it->first) != nums.end()) {
      labels[it->first] = 2;
    } else if (nums.find(a - it->first) != nums.end()) {
      labels[it->first] = 0; // only A
      singletons.push(*it);
    } else if (nums.find(b - it->first) != nums.end()) {
      labels[it->first] = 1; // only B
      singletons.push(*it);
    } else {
      good = false;
    }
  }
  if (!good) {
    printf("NO");
  } else {
    while (singletons.size() > 0) {
      pair<int, int> p = singletons.front();
      singletons.pop();
      if (nums.find(p.first) == nums.end()) {
        continue;
      }
      nums.erase(p.first);
      if (labels[p.first] == 0) {
        out[p.second] = 0;
        if (labels.find(a - p.first) != labels.end() && labels[a - p.first] == 1) {
          good = false;
          break;
        }
        labels[a - p.first] = 0;
        if (nums.find(a - p.first) != nums.end()) {
          singletons.push(make_pair(a - p.first, nums[a - p.first]));
        }
      } else if (labels[p.first] == 1) {
        out[p.second] = 1;
        if (labels[b - p.first] == 0) {
          good = false;
          break;
        }
        labels[b - p.first] = 1;
        if (nums.find(b - p.first) != nums.end()) {
          singletons.push(make_pair(b - p.first, nums[b - p.first]));
        }
      }
    }
    if (!good) {
      printf("NO");
    } else {
      for (auto it = nums.begin(); it != nums.end(); it++) {
        out[it->second] = 1;
      }
      printf("YES\n");
      for (int i = 0; i < n; i++) {
        if (i != n - 1) {
          printf("%d ", out[i]);
        } else {
          printf("%d", out[i]);
        }
      }

    }
  }
}
