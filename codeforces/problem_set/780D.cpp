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
#define print_container(c) cseen << c << endl;
#endif

using namespace std;

int main () {
  int n;
  scanf("%d", &n);
  vector<pair<string, string>> names;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    names.push_back(make_pair(string(a.begin(), a.begin() + 3), string(b.begin(), b.begin() + 1)));
  }

  vector<string> gotta_switch(n);
  map<string, int> seen_fronts;
  for (int i = 0; i < n; i++) {
    seen_fronts[names[i].first]++;
  }

  queue<int> q;
  vector<bool> bad_i(n);
  map<string, int> good_a;
  for (int i = 0; i < n; i++) {
    if (seen_fronts[names[i].first] > 1) {
      q.push(i);
      bad_i[i] = true;
    } else {
      good_a[names[i].first] = i;
    }
  }

  vector<string> result(n);
  set<string> seen;
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    string new_name;
    new_name += names[i].first[0];
    new_name += names[i].first[1];
    new_name += names[i].second[0];
    if (!seen.insert(new_name).second) {
      printf("NO");
      return 0;
    }
    result[i] = new_name;
    if (good_a.find(new_name) != good_a.end()) {
      int conv = good_a[new_name];
      bad_i[conv] = true;
      q.push(conv);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!bad_i[i]) {
      result[i] = names[i].first;
      if (!seen.insert(names[i].first).second) {
        printf("NO");
        return 0;
      }
    }
  }

  printf("YES\n");
  for (int i = 0; i < result.size(); i++) {
    printf("%s\n", result[i].c_str());
  }
}
