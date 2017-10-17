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

vector<pair<int, int>> get_factors(int n) {
  int d = 1;
  vector<pair<int, int>> out;
  int start = n;
  for (int i = 2; i * i <= start; i++) {
    pair<int, int> factor = {i, 0};
    while (n % i == 0) {
      n /= i;
      factor.second++;
    }
    if (factor.second > 0) {
      out.push_back(factor);
    }
  }
  if (n != 1) {
    out.push_back({n, 1});
  }
  return out;
}

void get_divisors_helper(int index, int result, vector<pair<int, int>>& factors, vector<int>& out) {
  if (index == factors.size()) {
    return out.push_back(result);
  }
  for (int i = 0; i <= factors[index].second; i++) {
    get_divisors_helper(index + 1, result, factors, out);
    result *= factors[index].first;
  }
}

vector<int> get_divisors(vector<pair<int, int>>& factors) {
  vector<int> out;
  get_divisors_helper(0, 1, factors, out);
  return out;
}

int main () {
  int a, b;
  scanf("%d %d", &a, &b);
  vector<pair<int, int>> a_factors = get_factors(a);
  vector<int> a_divisors = get_divisors(a_factors);
  vector<pair<int, int>> b_factors = get_factors(b);
  vector<int> b_divisors = get_divisors(b_factors);
  vector<int> intersection;
  sort(a_divisors.begin(), a_divisors.end());
  sort(b_divisors.begin(), b_divisors.end());
  set_intersection(a_divisors.begin(), a_divisors.end(), b_divisors.begin(), b_divisors.end(), inserter(intersection, intersection.begin()));
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int index = upper_bound(intersection.begin(), intersection.end(), r) - intersection.begin();
    index--;
    if (index == -1 || intersection[index] < l) {
      printf("-1\n");
    } else {
      printf("%d\n", intersection[index]);
    }
  }
}
