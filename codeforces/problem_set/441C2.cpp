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


int n, m, k;
void next(pair<int, int>& p, bool& left_to_right) {
  if (left_to_right) {
    p.second++;
    if (p.second > m) {
      p.second--;
      p.first++;
      left_to_right = false;
    }
  } else {
    p.second--;
    if (p.second == 0) {
      p.second++;
      p.first++;
      left_to_right = true;
    }
  }
}

int main () {
  scanf("%d %d %d", &n, &m, &k);
  pair<int, int> current = {1, 0};
  bool left_to_right = true;
  vector<vector<pair<int, int>>> coords;
  int count = 0;
  for (int i = 0; i < k; i++) {
    vector<pair<int, int>> tube;
    if (i < k - 1) {
      for (int j = 0; j < 2; j++) {
        next(current, left_to_right);
        count++;
        tube.push_back(current);
      }
    } else {
      while (count < n*m) {
        next(current, left_to_right);
        count++;
        tube.push_back(current);
      }
    }
    coords.push_back(tube);
  }
  for (int i = 0; i < coords.size(); i++) {
    printf("%d ", coords[i].size());
    for (int j = 0; j < coords[i].size(); j++) {
      printf("%d %d ", coords[i][j].first, coords[i][j].second);
    }
    printf("\n");
  }
}
