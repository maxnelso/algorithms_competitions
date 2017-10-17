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

struct team {
  int solved;
  int penalty;

  bool operator<(team other) const {
    if (solved < other.solved) {
      return true;
    }

    if (solved > other.solved) {
      return false;
    }

    return penalty > other.penalty;
  }


  bool operator==(team other) const {
    return solved == other.solved && penalty == other.penalty;
  }

};

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<team> teams;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    team t;
    t.solved = a;
    t.penalty = b;
    teams.push_back(t);
  }
  sort(teams.rbegin(), teams.rend());
  k--;

  // left
  int out = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (teams[i] == teams[k]) {
      out++;
    }
  }

  // right
  for (int i = k + 1; i < n; i++) {
    if (teams[i] == teams[k]) {
      out++;
    }
  }

  printf("%d", out + 1);
  return 0;

}
