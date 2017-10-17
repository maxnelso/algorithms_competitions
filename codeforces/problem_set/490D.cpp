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

set<pair<pair<int, int>, int>> first_bar;
set<pair<pair<int, int>, int>> second_bar;
set<pair<int, int>> seen;

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int a, b, c, d;
  scanf("%d %d", &a, &b);
  scanf("%d %d", &c, &d);
  stack<pair<pair<int, int>, int>> s; // dimensions, turns
  s.push(make_pair(make_pair(a, b), 0));
  while (!s.empty()) {
    pair<int, int> dimensions = s.top().first;
    int turns = s.top().second;
    seen.insert(dimensions);
    first_bar.insert(make_pair(make_pair(dimensions.first, dimensions.second), turns));
    s.pop();
    if (dimensions.first % 2 == 0) {
      pair<int, int> half = make_pair(dimensions.first / 2, dimensions.second);
      if (seen.find(half) == seen.end()) {
        s.push(make_pair(half, turns + 1));
      }
    }
    if (dimensions.second % 2 == 0) {
      pair<int, int> half = make_pair(dimensions.first, dimensions.second / 2);
      if (seen.find(half) == seen.end()) {
        s.push(make_pair(half, turns + 1));
      }
    }
    if (dimensions.first % 3 == 0) {
      pair<int, int> two_thirds = make_pair(2 * dimensions.first / 3, dimensions.second);
      if (seen.find(two_thirds) == seen.end()) {
        s.push(make_pair(two_thirds, turns + 1));
      }
    }
    if (dimensions.second % 3 == 0) {
      pair<int, int> two_thirds = make_pair(dimensions.first, 2 * dimensions.second / 3);
      if (seen.find(two_thirds) == seen.end()) {
        s.push(make_pair(two_thirds, turns + 1));
      }
    }
  }
  s.push(make_pair(make_pair(c, d), 0));
  seen.clear();
  while (!s.empty()) {
    pair<int, int> dimensions = s.top().first;
    int turns = s.top().second;
    seen.insert(dimensions);
    second_bar.insert(make_pair(make_pair(dimensions.first, dimensions.second), turns));
    s.pop();
    if (dimensions.first % 2 == 0) {
      pair<int, int> half = make_pair(dimensions.first / 2, dimensions.second);
      if (seen.find(half) == seen.end()) {
        s.push(make_pair(half, turns + 1));
      }
    }
    if (dimensions.second % 2 == 0) {
      pair<int, int> half = make_pair(dimensions.first, dimensions.second / 2);
      if (seen.find(half) == seen.end()) {
        s.push(make_pair(half, turns + 1));
      }
    }
    if (dimensions.first % 3 == 0) {
      pair<int, int> two_thirds = make_pair(2 * dimensions.first / 3, dimensions.second);
      if (seen.find(two_thirds) == seen.end()) {
        s.push(make_pair(two_thirds, turns + 1));
      }
    }
    if (dimensions.second % 3 == 0) {
      pair<int, int> two_thirds = make_pair(dimensions.first, 2 * dimensions.second / 3);
      if (seen.find(two_thirds) == seen.end()) {
        s.push(make_pair(two_thirds, turns + 1));
      }
    }
  }
  print_container(first_bar);
  print_container(second_bar);
  auto first_it = first_bar.rbegin();
  auto second_it = second_bar.rbegin();
  while (first_it != first_bar.begin() && second_it != second_bar.begin()) {
    pair<pair<int, int>, int> first_area = *first_it;
    pair<pair<int, int>, int> second_area = *second_it;
    if (first_area.first == second_area.first) {
      return 0;
    }
  }
}
