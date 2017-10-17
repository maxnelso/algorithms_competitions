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

int n, m, k;

pair<int, int> get_next(pair<int, int> p) {
  int i = p.first;
  int j = p.second;
  if (i % 2 == 1) { // Left to right
    if (j == m) {
      return make_pair(i + 1, j);
    }
    return make_pair(i, j + 1);
  } else { // Right to left
    if (j == 1) {
      return make_pair(i + 1, j);
    }
    return make_pair(i, j - 1);
  }
}

int main () {
  scanf("%d %d %d", &n, &m, &k);

  vector<vector<pair<int, int>>> out;
  pair<int, int> current = make_pair(1, 1);
  int c = 0;
  while (k != 1) {
    vector<pair<int, int>> just_two;
    just_two.push_back(current);
    current = get_next(current);
    just_two.push_back(current);
    current = get_next(current);
    k--;
    c += 2;
    out.push_back(just_two);
  }

  vector<pair<int, int>> leftovers;
  while (c != m * n) {
    leftovers.push_back(current);
    current = get_next(current);
    c++;
  }

  out.push_back(leftovers);

  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i].size());
    for (int j = 0; j < out[i].size(); j++) {
      printf("%d %d ", out[i][j].first, out[i][j].second);
    }
    printf("\n");
  }
}
