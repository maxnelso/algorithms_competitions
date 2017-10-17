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

vector<vector<int>> alice;
vector<vector<int>> bob;

struct cycle {
  int a;
  int b;
  int d;
};

cycle check_cycle(int a, int b) {
  set<pair<int, int>> seen;
  int alice_score = 0;
  int bob_score = 0;
  int draws = 0;
  int start_a = a;
  int start_b = b;
  // printf("Checking %d %d\n", a, b);
  while (true) {
    pair<int, int> p = make_pair(a, b);
    if (seen.find(p) != seen.end()) {
      break;
    } else {
      seen.insert(make_pair(a, b));
    }


    // printf("Looking at %d %d\n", a, b);
    if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) {
      alice_score++;
    } else if ((b == 1 && a == 3) || (b == 2 && a == 1) || (b == 3 && a == 2)) {
      bob_score++;
    } else {
      draws++;
    }

    int a_new = alice[a - 1][b - 1];
    int b_new = bob[a - 1][b - 1];
    a = a_new;
    b = b_new;
  }
  if (a == start_a && b == start_b) {
    cycle c;
    c.a = alice_score;
    c.b = bob_score;
    c.d = draws;
    return c;
  }

  cycle c;
  c.a = -1;
  c.b = -1;
  c.d = -1;
  return c;
}

int main () {
  long long k, a, b;
  cin >> k >> a >> b;
  for (int i = 0; i < 3; i++) {
    vector<int> row;
    for (int j = 0; j < 3; j++) {
      int a;
      scanf("%d", &a);
      row.push_back(a);
    }
    alice.push_back(row);
  }

  for (int i = 0; i < 3; i++) {
    vector<int> row;
    for (int j = 0; j < 3; j++) {
      int a;
      scanf("%d", &a);
      row.push_back(a);
    }
    bob.push_back(row);
  }

  long long a_diff = 0;
  long long b_diff = 0;
  cycle cycle_diff;
  while (true) {
    cycle_diff = check_cycle(a, b);
    if (cycle_diff.a == -1) {
      if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) {
        a_diff++;
      } else if ((b == 1 && a == 3) || (b == 2 && a == 1) || (b == 3 && a == 2)) {
        b_diff++;
      }
      int a_new = alice[a - 1][b - 1];
      int b_new = bob[a - 1][b - 1];
      a = a_new;
      b = b_new;
      k--;
      if (k == 0) {
        cout << a_diff << " " << b_diff;
        return 0;
      }
    } else {
      break;
    }

  }
  if (cycle_diff.a == 0 && cycle_diff.b == 0) {
    cout << a_diff << " " << b_diff;
    return 0;
  }
  // printf("diffs %d %d\n", a_diff, b_diff);
  // printf("cycle diff %d %d %d\n", cycle_diff.a, cycle_diff.b, cycle_diff.d);
  long long cycle_rounds = k / (cycle_diff.a + cycle_diff.b + cycle_diff.d);
  // printf("cycle_rounds %d\n", cycle_rounds);
  long long alice_score = cycle_rounds * cycle_diff.a;
  long long bob_score = cycle_rounds * cycle_diff.b;
  k -= cycle_rounds * (cycle_diff.a + cycle_diff.b + cycle_diff.d);
  // printf("K: %d, %d %d\n", k, a, b);
  for (int i = 0; i < k; i++) {
    if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) {
      alice_score++;
    } else if ((b == 1 && a == 3) || (b == 2 && a == 1) || (b == 3 && a == 2)) {
      bob_score++;
    }
    int a_new = alice[a - 1][b - 1];
    int b_new = bob[a - 1][b - 1];
    a = a_new;
    b = b_new;
  }
  cout << alice_score + a_diff << " " << bob_score + b_diff;
}
