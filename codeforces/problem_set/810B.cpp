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
#include <unordered_map>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

struct day {
  int products;
  int people;

  bool operator<(day other) const {
    int my_normal = min(products, people);
    int their_normal = min(other.products, other.people);
    int my_better = min(2 * products, people);
    int their_better = min(2 * other.products, other.people);
    int my_diff = my_better - my_normal;
    int their_diff = their_better - their_normal;
    return my_diff < their_diff;
  }
};

int main () {
  int n, f;
  scanf("%d %d", &n, &f);
  vector<day> days;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    day d;
    d.products = a;
    d.people = b;
    days.push_back(d);
  }
  sort(days.rbegin(), days.rend());
  long long out = 0;
  for (int i = 0; i < n; i++) {
    if (i < f) {
      out += min(2 * days[i].products, days[i].people);
    } else {
      out += min(days[i].products, days[i].people);
    }
  }
  cout << out;
}
