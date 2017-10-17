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

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> people;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    people.push_back(a);
  }
  sort(people.begin(), people.end());
  int current_floor = 1;
  int out = people[people.size() - 1] - 1;
  int i = 0;
  while (current_floor != people[people.size() - 1]) {
    int people_left = n - i;
    int trips_up = 0;
    int trips_down = 0;
    if (people_left <= k) {
      trips_up = 1;
    } else if (people_left % k == 0) {
      trips_up = people_left / k;
      trips_down = trips_up - 1;
    } else {
      trips_up = people_left / k + 1;
      trips_down = trips_up - 1;
    }
    out += trips_up;
    out += trips_down;
    current_floor++;
    while (people[i] == current_floor && i < people.size()) {
      ++i;
    }
    if (i == n) {
      break;
    }
  }
  printf("%d", out);
}
