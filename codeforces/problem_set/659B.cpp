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

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  map<int, vector<pair<int, string>>> kids;
  for (int i = 0; i < n; i++) {
    char c[256];
    int a, b;
    scanf("%s %d %d", c, &a, &b);
    string s(c);
    kids[a].push_back(make_pair(b, s));
  }

  for (auto& p : kids) {
    sort(p.second.rbegin(), p.second.rend());
  }

  for (auto p : kids) {
    if (p.second.size() == 2) {
      printf("%s %s\n", p.second[0].second.c_str(), p.second[1].second.c_str());
    } else if (p.second[1].first == p.second[2].first) {
      printf("?\n");
    } else {
      printf("%s %s\n", p.second[0].second.c_str(), p.second[1].second.c_str());
    }
  }

}
