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
  int n, v;
  scanf("%d %d", &n, &v);
  vector<pair<int, int>> bad_trees;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    bad_trees.push_back(make_pair(a, b));
  }
  vector<pair<int, int>> trees;
  map<int, int> days;
  sort(bad_trees.begin(), bad_trees.end());
  for (int i = 0; i < bad_trees.size(); i++) {
    if (days.find(bad_trees[i].first) != days.end()) {
      days[bad_trees[i].first] += bad_trees[i].second;
    } else {
      days[bad_trees[i].first] = bad_trees[i].second;
    }
  }
  for (map<int, int>::iterator it = days.begin(); it != days.end(); it++) {
    trees.push_back(make_pair(it->first, it->second));
  }
  sort(trees.begin(), trees.end());
  int current_time;
  int count = 0;
  for (int i = 0; i < trees.size() + 1; i++) {
    if (i < trees.size()) {
      current_time = trees[i].first;
    } else {
      current_time++;
    }
    int v_copy = v;
    if (i > 0 && current_time - 1 == trees[i-1].first) {
      int change = min(trees[i-1].second, v_copy);
      trees[i-1].second -= change;
      v_copy -= change;
      count += change;
    }
    if (i < trees.size()) {
      int change = min(trees[i].second, v_copy);
      trees[i].second -= change;
      count += change;
    }
  }
  printf("%d", count);
}
