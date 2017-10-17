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

struct person {
  int x;
  int speed;
  bool lefty;

  bool operator<(person other) {
    return this->x < other.x;
  }
};

int main () {
  vector<person> people;
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    int x, speed, d;
    scanf("%d %d %d", &x, &speed, &d);
    person p;
    p.x = x;
    p.speed = speed;
    p.lefty = d == 1;
    people.push_back(p);
  }

  sort(people.begin(), people.end());
  const int RIGHT_END = (int) 10e6;
  for (int i = 0; i < people.size() - 1; i++) {
    person a = people[i];
    person b = people[i + 1];
    if (a.lefty == b.lefty) {
      continue;
    }

    if (a.lefty) { // Left is on the left, gotta catch up
      float time_to_left = (float) a.x / (float) a.speed;
      float time_to_right = (RIGHT_END - (float) b.x) / (float) b.speed;
    } else { // Left is on the right, we are gonna collide

    }
  }
}
