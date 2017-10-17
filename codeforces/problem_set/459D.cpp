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

struct FenwickTree {
  typedef int T;
  vector<T> tree;
  FenwickTree(int n): tree(n + 1, 0) {}

  void add(int index, T value) {
    for (int i = index; i < tree.size(); i += (i & -i)) { // Getting parent
      tree[i] += value;
    }
  }

  T sum(int index) { // [0, i)
    int out = 0;
    for (int i = index - 1; i > 0; i -= (i & -i)) { // Getting child
      out += tree[i];
    }
    return out;
  }

  T sum(int l, int r) {
    return sum(r) - sum(l);
  }
};

int main () {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> left_query(n);
  map<int, int> left_counts;
  for (int i = 0; i < n; i++) {
    left_counts[a[i]]++;
    left_query[i] = left_counts[a[i]];
  }
  vector<int> right_query(n);
  map<int, int> right_counts;
  for (int i = n - 1; i >= 0; i--) {
    right_counts[a[i]]++;
    right_query[i] = right_counts[a[i]];
  }
  FenwickTree fenwickTree(n);
  long long out = 0;
  for (int i = n - 1; i >= 0; i--) {
    out += fenwickTree.sum(left_query[i]);
    fenwickTree.add(right_query[i], 1);
  }
  cout << out;
}
