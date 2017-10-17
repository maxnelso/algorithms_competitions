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

int longest_increasing_subsequence(vector<int>& A) {
  set<int> current_best;
  for (int i = 0; i < A.size(); i++) {
    if (current_best.empty() || (*(current_best.rbegin()) < A[i])) {
      current_best.insert(A[i]);
    } else {
      auto it = current_best.lower_bound(A[i]);
      current_best.erase(it);
      current_best.insert(A[i]);
    }
  }
  return current_best.size();
}

int main () {
  int n;
  scanf("%d", &n);
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    nums.push_back(a);
  }
  printf("%d", longest_increasing_subsequence(nums));
}
