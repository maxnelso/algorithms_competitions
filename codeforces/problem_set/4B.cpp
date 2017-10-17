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

  int d, sum_time;
  scanf("%d %d", &d, &sum_time);
  vector<pair<int, int>> times;
  map<int, vector<int>> can_reach;
  can_reach[sum_time] = vector<int>();

  for (int i = 0; i < d; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    map<int, vector<int>> new_can_reach;
    for (auto p : can_reach) {
      int time = p.first;
      vector<int> path = p.second;
      for (int j = a; j <= b; j++) {
        int new_time = time - j;
        if (new_time < 0) {
          break;
        }
        vector<int> new_path = path;
        new_path.push_back(j);
        new_can_reach[new_time] = new_path;
      }
    }
    can_reach = new_can_reach;
  }
  if (can_reach.find(0) != can_reach.end()) {
    printf("YES\n");
    vector<int> path = can_reach[0];
    for (int i = 0; i < path.size(); i++) {
      printf("%d ", path[i]);
    }
  } else {
    printf("NO");
  }
}
