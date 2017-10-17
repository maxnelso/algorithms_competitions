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
int a, b;

vector<int> solve(vector<int>& archers, int start) {
  vector<int> out;
  //print_container(archers);
  for (int i = start; i < archers.size() - 1; i++) {
    if (archers[i] >= 0) {
      // Can either shoot at or the next
      int max_side_shots = (int) ceil(static_cast<float>(archers[i] + 1) / b);
      for (int side_shots = 0; side_shots <= max_side_shots; side_shots++) {
        int left_hp = archers[i] - (side_shots * b);
        int direct_shots = (int) ceil(static_cast<float>(left_hp + 1) / a);
        archers[i] -= side_shots * b + direct_shots * a;
        archers[i+1] -= side_shots * a + direct_shots * b;
        archers[i-1] -= direct_shots * b;
        archers[i+2] -= side_shots * b;
        vector<int> path;
        //printf("before? %d %d %d ", i, archers[i-1], archers[i]);
        vector<int> solved = solve(archers, i + 1);
        archers[i] += side_shots * b + direct_shots * a;
        archers[i+1] += side_shots * a + direct_shots * b;
        archers[i-1] += direct_shots * b;
        archers[i+2] += side_shots * b;
        if (out.empty() || direct_shots + side_shots + solved.size() < out.size()) {
          for (int j = 0; j < direct_shots; j++) {
            path.push_back(i + 1);
          }
          for (int j = 0; j < side_shots; j++) {
            path.push_back(i + 2);
          }
          path.insert(path.end(), solved.begin(), solved.end());
          out = path;
        }
      }
      return out;
    }
  }
  return out;
}

int main () {
  int n;
  scanf("%d %d %d", &n, &a, &b);
  vector<int> archers;
  for (int i = 0; i < n; i++) {
    int h;
    scanf("%d", &h);
    archers.push_back(h);
  }
  vector<int> out;
  while (archers[0] >= 0) {
    out.push_back(2);
    archers[0] -= b;
    archers[1] -= a;
    archers[2] -= b;
  }
  while (archers[n - 1] >= 0) {
    out.push_back(n - 1);
    archers[n-1] -= b;
    archers[n-2] -= a;
    archers[n-3] -= b;
  }
  //printf("start\n");
  //print_container(archers);
  vector<int> rest = solve(archers, 1);
  out.insert(out.end(), rest.begin(), rest.end());
  printf("%d\n", out.size());
  for (int i = 0; i < out.size(); i++) {
    printf("%d ", out[i]);
  }


}
