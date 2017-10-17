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

const int MAXN = 55;
int memo[MAXN][2];
bool seen[MAXN][2];
vector<int> pies;

int solve(int index, bool alice) {
  if (seen[index][alice]) {
    return memo[index][alice];
  }
  int out = alice ? 0 : 100000;
  if (alice) {
    if (index == pies.size() - 1) {
      // just take the last one
      out = pies[index];
    } else {
      int take = pies[index] + solve(index + 1, false);
      int dont_take = solve(index + 1, true);
      out = max(take, dont_take);
    }
  } else {
    if (index == pies.size() - 1) {
      out = 0;
      // just take the last one
    } else {
      int take = solve(index + 1, true);
      int dont_take = pies[index] + solve(index + 1, false);
      out = min(take, dont_take);
    }
  }
  seen[index][alice] = true;
  memo[index][alice] = out;
  return out;
}

int main () {
  int n;
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    pies.push_back(a);
    total += a;
  }

  solve(0, false);
  printf("%d %d", memo[0][0], total - memo[0][0]);
}
