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

using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  vector<int> stones;
  vector<int> sorted_stones;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    stones.push_back(a);
    sorted_stones.push_back(a);
  }
  sort(sorted_stones.begin(), sorted_stones.end());
  vector<long long> partial_sums;
  vector<long long> partial_sums_sorted;
  partial_sums.push_back(0);
  partial_sums_sorted.push_back(0);
  for (int i = 0; i < stones.size(); i++) {
    partial_sums.push_back(stones[i] + partial_sums[i]);
    partial_sums_sorted.push_back(sorted_stones[i] + partial_sums_sorted[i]);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r, t;
    scanf("%d %d %d", &t, &l, &r);
    l--;
    r--;
    if (t == 1) {
      cout << (partial_sums[r+1] - partial_sums[l]) << endl;
    } else {
      cout << (partial_sums_sorted[r+1] - partial_sums_sorted[l]) << endl;
    }
  }
  setvbuf(stdout, NULL, _IONBF, 0);
}
