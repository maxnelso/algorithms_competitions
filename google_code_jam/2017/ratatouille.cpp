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

string FILENAME = "b-small";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int im_bad_at_math(int need, int have) {
  int start = have / need;
  int out = -1;
  for (int i = -5; i <= 5; i++) {
    int mid = start + i;
    if (mid >= 0 && .9 * (need * mid) <= have && 1.1 * (need * mid) >= have) {
      out = start + i;
    }
  }
  return out;
}

int im_bad_at_math_part_2(int need1, int have1, int need2, int have2) {
  int start = have1 / need1;
  set<int> goods;
  int out = -1;
  for (int i = -5; i <= 5; i++) {
    int mid = start + i;
    if (mid >= 0 && .9 * (need1 * mid) <= have1 && 1.1 * (need1 * mid) >= have1) {
      goods.insert(start + i);
    }
  }
  start = have2 / need2;
  for (int i = -100; i <= 100; i++) {
    int mid = start + i;
    if (mid >= 0 && .9 * (need2 * mid) <= have2 && 1.1 * (need2 * mid) >= have2 && goods.find(mid) != goods.end()) {
      out = mid;
    }
  }

  return out;
}



int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int n, p;
    scanf("%d %d", &n, &p);
    vector<int> rs;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      rs.push_back(a);
    }
    vector<vector<int>> packages;
    for (int i = 0; i < n; i++) {
      vector<int> package;
      for (int j = 0; j < p; j++) {
        int a;
        scanf("%d", &a);
        package.push_back(a);
      }
      packages.push_back(package);
    }
    if (n == 1) {
      int total = 0;
      for (int i = 0; i < packages[0].size(); i++) {
        total += im_bad_at_math(rs[0], packages[0][i]) != -1;
      }
      printf("%d\n", total);
    } else if (n == 2) {
      vector<int> indicies;
      for (int i = 0; i < p; i++) {
        indicies.push_back(i);
      }
      int best = 0;
      do {
        int out = 0;
        for (int i = 0; i < packages[1].size(); i++) {
          if (im_bad_at_math_part_2(rs[0], packages[0][indicies[i]], rs[1], packages[1][i]) != -1) {
            out++;
          }
        }
        best = max(out, best);
      } while (next_permutation(indicies.begin(), indicies.end()));
      printf("%d\n", best);
    }
  }
  fflush(stdout);
}
