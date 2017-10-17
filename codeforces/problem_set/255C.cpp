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

const int MAXN = 1000000 + 10;
vector<int> nums;

int merge_sort(vector<int>& a, vector<int>& b) {
  int out = 0;
  int i = 0;
  int j = 0;
  bool need_b = a[0] > b[0];
  while (i < a.size() && j < b.size()) {
    if (need_b) {
      if (out == 0 || b[j] > a[i - 1]) {
        need_b = false;
        out++;
      }
      j++;
    } else {
      if (out == 0 || b[j - 1] < a[i]) {
        need_b = true;
        out++;
      }
      i++;
    }
  }
  if (need_b) {
    if (j < b.size() && b[b.size() - 1] > a[a.size() - 1]) {
      out++;
    }
  } else {
    if (i < a.size() && b[b.size() - 1] < a[a.size() - 1]) {
      out++;
    }
  }
  return out;
}

int main () {
  int n;
  scanf("%d", &n);
  vector<vector<int>> indices(MAXN);

  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
    indices[a].push_back(i);
  }

  vector<int> uni;
  int out = 0;
  for (int i = 0; i < indices.size(); i++) {
    out = max(out, (int) indices[i].size());
    if (indices[i].size() > 0) {
      uni.push_back(i);
    }
  }

  for (int i = 0; i < uni.size(); i++) {
    for (int j = i + 1; j < uni.size(); j++) {
      out = max(out, merge_sort(indices[uni[i]], indices[uni[j]]));
    }
  }
  printf("%d", out);
}
