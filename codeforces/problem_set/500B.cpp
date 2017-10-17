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
  int n;
  scanf("%d", &n);
  vector<int> permutation;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    permutation.push_back(a);
  }
  vector<string> grid;
  for (int i = 0; i < n; i++) {
    char c[350];
    scanf("%s", c);
    string s(c);
    grid.push_back(s);
  }
  map<int, set<int>> reachable;
  for (int i = 0; i < n; i++) {
    set<int> reach;
    vector<int> to_see;
    map<int, bool> seen;
    to_see.push_back(i);
    reach.insert(i);
    while (to_see.size() > 0) {
      int a = to_see[to_see.size() - 1]; to_see.pop_back();
      reach.insert(a);
      seen[a] = true;
      for (int j = 0; j < n; j++) {
        if (grid[a][j] == '1' && seen.find(j) == seen.end()) {
          to_see.push_back(j);
          seen[j] = true;
        }
      }
    }
    reachable[i] = reach;
  }
  vector<int> out(n);
  for (int i = 0; i < n; i++) {
    int pos = find(permutation.begin(), permutation.end(), i + 1) - permutation.begin();
    int m = *min_element(reachable[pos].begin(), reachable[pos].end());
    out[m] = i + 1;
    for (int j = 0; j < n; j++) {
      if (find(reachable[j].begin(), reachable[j].end(), m) != reachable[j].end()) {
        reachable[j].erase(m);
      }
    }
  }
  for (int i = 0; i < out.size(); i++) {
    if (i == out.size() - 1) {
      printf("%d", out[i]);
    } else {
      printf("%d ", out[i]);
    }
  }
}
